/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:37:28 by mbico             #+#    #+#             */
/*   Updated: 2024/01/10 17:27:16 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include "../libft.h"

char	*get_next_line(int fd);
char	*ft_strjoin_free(char *s1, char *s2);
char	*ft_strdupn(const char *s);
int		ft_strbanlen(const char *s, char ban);
void	*ft_freeall_gnl(char *buffer, char *line);

#endif