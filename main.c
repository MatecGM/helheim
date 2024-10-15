
#include <stdio.h>
#include <stdlib.h>
#include <mpg123.h>
#include <portaudio.h>

#define FRAMES_PER_BUFFER 1152  // Taille de frame standard pour mp3
#define SAMPLE_RATE 44100       // Fréquence d'échantillonnage par défaut

// Fonction de callback pour PortAudio
static int audioCallback(const void *inputBuffer, void *outputBuffer,
                         unsigned long framesPerBuffer,
                         const PaStreamCallbackTimeInfo* timeInfo,
                         PaStreamCallbackFlags statusFlags,
                         void *userData) {
    mpg123_handle *mpgHandle = (mpg123_handle *)userData;
    unsigned char *out = (unsigned char*)outputBuffer;
    size_t done;
    int err = mpg123_read(mpgHandle, out, framesPerBuffer * sizeof(float) * 2, &done); // 2 canaux stéréo

    if (err == MPG123_DONE) {
        return paComplete;  // Fin du fichier
    }
    return paContinue;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file.mp3>\n", argv[0]);
        return -1;
    }

    const char *filename = argv[1];

    // Initialiser mpg123
    mpg123_handle *mpgHandle;
    int err;
    long rate;
    int channels, encoding;
    mpg123_init();
    mpgHandle = mpg123_new(NULL, &err);
    if (mpg123_open(mpgHandle, filename) != MPG123_OK) {
        fprintf(stderr, "Erreur lors de l'ouverture du fichier MP3: %s\n", mpg123_strerror(mpgHandle));
        return -1;
    }

    // Obtenir les informations sur le fichier MP3 (fréquence d'échantillonnage, canaux)
    mpg123_getformat(mpgHandle, &rate, &channels, &encoding);
    mpg123_format_none(mpgHandle);
    mpg123_format(mpgHandle, rate, channels, encoding);

    // Initialiser PortAudio
    PaError paErr;
    PaStream *stream;
    paErr = Pa_Initialize();
    if (paErr != paNoError) {
        fprintf(stderr, "Erreur lors de l'initialisation de PortAudio: %s\n", Pa_GetErrorText(paErr));
        return -1;
    }

    // Ouvrir un flux audio PortAudio
    paErr = Pa_OpenDefaultStream(&stream,
                                 0,              // Pas d'entrée
                                 channels,       // Nombre de canaux de sortie (stéréo ou mono)
                                 paFloat32,      // Format d'échantillon : 32 bits flottants
                                 rate,           // Fréquence d'échantillonnage
                                 FRAMES_PER_BUFFER,  // Taille du buffer
                                 audioCallback,  // Callback pour lire les données MP3
                                 mpgHandle);     // Données utilisateur (mpg123_handle)
    if (paErr != paNoError) {
        fprintf(stderr, "Erreur lors de l'ouverture du flux audio: %s\n", Pa_GetErrorText(paErr));
        return -1;
    }

    // Démarrer le flux audio
    paErr = Pa_StartStream(stream);
    if (paErr != paNoError) {
        fprintf(stderr, "Erreur lors du démarrage du flux audio: %s\n", Pa_GetErrorText(paErr));
        return -1;
    }

    // Attendre la fin du fichier MP3
    while ((paErr = Pa_IsStreamActive(stream)) == 1) {
        Pa_Sleep(100);
    }
    if (paErr < 0) {
        fprintf(stderr, "Erreur lors de la lecture du flux audio: %s\n", Pa_GetErrorText(paErr));
    }

    // Nettoyer
    Pa_StopStream(stream);
    Pa_CloseStream(stream);
    Pa_Terminate();
    mpg123_close(mpgHandle);
    mpg123_delete(mpgHandle);
    mpg123_exit();

    printf("Lecture terminée.\n");
    return 0;
}
