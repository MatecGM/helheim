#include <portaudio.h>
#include <mpg123.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 4096  // Taille du tampon PCM

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file.mp3>\n", argv[0]);
        return 1;
    }

    const char *filename = "../Snare.mp3";
    mpg123_handle *mh = NULL;
    unsigned char buffer[BUFFER_SIZE];
    size_t bytes_read;
    int err;

    // Variables pour PortAudio
    PaStream *stream;
    PaError pa_err;
    int channels, encoding;
    long rate;

    // Initialisation de mpg123
    mpg123_init();
    mh = mpg123_new(NULL, &err);
    if (mh == NULL) {
        fprintf(stderr, "Erreur mpg123: %s\n", mpg123_plain_strerror(err));
        return 1;
    }

    mpg123_open(mh, filename);
    mpg123_getformat(mh, &rate, &channels, &encoding);

    // Initialisation de PortAudio
    pa_err = Pa_Initialize();
    if (pa_err != paNoError) {
        fprintf(stderr, "Erreur PortAudio: %s\n", Pa_GetErrorText(pa_err));
        return 1;
    }

    // Ouvrir un flux audio
    pa_err = Pa_OpenStream(
        &stream,
        NULL, // Pas d'entrée
        &(PaStreamParameters){
            .device = Pa_GetDefaultOutputDevice(),
            .channelCount = channels,
            .sampleFormat = paInt16,  // mpg123 renvoie souvent des int16 PCM
            .suggestedLatency = Pa_GetDeviceInfo(Pa_GetDefaultOutputDevice())->defaultLowOutputLatency,
            .hostApiSpecificStreamInfo = NULL},
        rate,
        paFramesPerBufferUnspecified,
        paClipOff,
        NULL,
        NULL);

    if (pa_err != paNoError) {
        fprintf(stderr, "Erreur ouverture flux: %s\n", Pa_GetErrorText(pa_err));
        return 1;
    }

    Pa_StartStream(stream);

    // Lecture et lecture du fichier MP3
    while (mpg123_read(mh, buffer, BUFFER_SIZE, &bytes_read) == MPG123_OK) {
        Pa_WriteStream(stream, buffer, bytes_read / sizeof(short));  // Écrire en PCM
    }

    // Nettoyage
    Pa_StopStream(stream);
    Pa_CloseStream(stream);
    Pa_Terminate();

    mpg123_close(mh);
    mpg123_delete(mh);
    mpg123_exit();

    printf("Lecture terminée.\n");
    return 0;
}
