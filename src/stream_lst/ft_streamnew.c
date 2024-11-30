/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_streamnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 10:56:42 by mbico             #+#    #+#             */
/*   Updated: 2024/11/30 11:27:07 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <head.h>
#include <portaudio.h>

static PaError	init_stream(t_stream *stream, int32_t channel)
{
	PaError				err;
	PaStreamParameters	par;

	par.device = Pa_GetDefaultOutputDevice();
	par.channelCount = channel;
	par.sampleFormat = paInt16;
    par.suggestedLatency = Pa_GetDeviceInfo(Pa_GetDefaultOutputDevice())->defaultLowOutputLatency;
	par.hostApiSpecificStreamInfo = NULL;
	err = Pa_OpenStream(&stream->stream, NULL, &par,RATE, paFramesPerBufferUnspecified, paClipOff, NULL, NULL);
	return (err);
}

t_stream	*ft_streamnew(t_sound *sound)
{
	t_stream	*l;

	l = malloc(sizeof(t_stream));
	if (l == NULL)
		return (NULL);
	l->sound = sound;
	l->channel = sound->channel;
	l->rate = sound->rate;
	if (init_stream(l, l->channel) != paNoError)
	{
		free (l);
		return (NULL);
	}
	l->next = NULL;
	return (l);
}
