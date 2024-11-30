/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 07:41:48 by mbico             #+#    #+#             */
/*   Updated: 2024/11/30 13:24:02 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H

# include <mpg123.h>
# include <portaudio.h>
# include <stdint.h>
# include <stdio.h>


# define BUFFER_SIZE 64
# define RATE		44100

typedef enum e_bool
{
	ERROR = -1,
	FALSE,
	TRUE,
}	t_bool;

typedef struct	s_sound
{
	int32_t			channel;
	int32_t			encoding;
	uint8_t			buffer[BUFFER_SIZE];
	long			rate;
	mpg123_handle	*mh;
}	t_sound;

typedef struct s_stream
{
	t_sound		*sound;
	PaStream	*stream;
	int32_t		channel;
	long		rate;
	struct s_stream	*next;
}	t_stream;

t_stream	*ft_streamnew(t_sound *sound);
t_stream	*alloc_stream(t_stream *stream, t_sound *sound, uint32_t *i);
t_bool		play_sound(t_stream *stream);

#endif
