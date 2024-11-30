/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_stream.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 10:43:00 by mbico             #+#    #+#             */
/*   Updated: 2024/11/30 12:36:28 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <head.h>

t_stream	*alloc_stream(t_stream *stream, t_sound *sound, uint32_t *i)
{
	t_stream	*new;
	t_stream	*ptr;

	ptr = stream;
	*i = 0;
	while (stream && ptr->next)
	{
		if (!ptr->sound && ptr->channel == sound->channel
			&& ptr->rate == sound->rate)
		{
			ptr->sound = sound;
			return (stream);
		}
		ptr = ptr->next;
		(*i) ++;
	}
	new = ft_streamnew(sound);
	if (!new)
		return (NULL);
	if (ptr)
		ptr->next = new;
	else
		stream = new;
	Pa_StartStream(new->stream);
	return (stream);
}
