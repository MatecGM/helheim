/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 07:21:41 by mbico             #+#    #+#             */
/*   Updated: 2024/10/21 11:57:18 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <portaudio.h>
#include <mpg123.h>
#include <stdio.h>
#include <stdint.h>
#include "head.h"

void	close_lib(uint8_t nb)
{
	const void (*exit_lib[2])(void) = {(void *) Pa_Terminate, (void *)mpg123_exit};
	uint8_t	i;

	i = 0;
	while (i < nb && i < 2)
		exit_lib[i++]();
}

t_bool	init_palib(void)
{
	PaError	err;

	err = Pa_Initialize();
	Pa_Terminate();
	if (err)
	{
		printf("PortAudio init error : %s\n", Pa_GetErrorText(err));
		return (TRUE);
	}
	return (FALSE);
}

t_bool	init_mpglib(void)
{
	int32_t	err;
	char	*str;

	err = mpg123_init();
	if (err)
	{
		printf("Mpg123 init error : %s\n", mpg123_plain_strerror(err));
		close_lib(1);
		return (TRUE);
	}
	return (FALSE);
}

int	main(int argc, char **argv)
{
	if (init_palib())
		return (1);
	if (init_mpglib())
		return (1);
	printf("end program\n");

	close_lib(2);
	return (0);
}
