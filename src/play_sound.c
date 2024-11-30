/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_sound.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 11:47:39 by mbico             #+#    #+#             */
/*   Updated: 2024/11/30 13:24:13 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <head.h>

t_sound	get_sound(char *path)
{
	t_sound			sound;
	int32_t			err;

	sound.mh = mpg123_new(NULL, &err);
	if (sound.mh == NULL)
		fprintf(stderr, "Erreur mpg123: %s\n", mpg123_plain_strerror(err));
	else
	{
		mpg123_open(sound.mh, path);
		mpg123_getformat(sound.mh, &sound.rate, &sound.channel, &sound.encoding);
	}
	return (sound);
}

void	read_sound_file(t_stream *stream, uint32_t i)
{
	t_stream	*ptr;
	size_t		bytes_read;

	ptr = stream;
	while (ptr && ptr->next && i++ > 0)
		ptr = ptr->next;
	while (mpg123_read(ptr->sound->mh, ptr->sound->buffer, BUFFER_SIZE, &bytes_read) == MPG123_OK)
        Pa_WriteStream(ptr->stream, ptr->sound->buffer, bytes_read / sizeof(int32_t));
    mpg123_close(ptr->sound->mh);
    mpg123_delete(ptr->sound->mh);
	stream->sound = NULL;
}

t_bool	play_sound(t_stream *stream)
{
	t_sound		sound;
	uint32_t	i;
	
	sound = get_sound("../Snare.mp3");
	short *samples = (short *)sound.buffer;
	for (int i = 0; i < 10; i++) {
		printf("Échantillon %d : %d\n", i, samples[i]);
	}
	if (!sound.mh)
		return (FALSE);
	stream = alloc_stream(stream, &sound, &i);
	if (!stream)
		return (FALSE);
	read_sound_file(stream, i);
	return (TRUE);
}
