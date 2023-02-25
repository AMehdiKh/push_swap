/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khel <ael-khel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:29:42 by ael-khel          #+#    #+#             */
/*   Updated: 2023/02/25 06:40:31 by ael-khel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*ft_strjoin(char **reserve, char *buffer);
char	*ft_check_nl(char **reserve);
char	*ft_strdup(char **reserve);
char	*get_next_line(int fd);

void	ft_strlcpy(char *dst, const char *src, size_t size);

void	*ft_free(char **ptr1);

size_t	ft_strlen(const char *s);

int		ft_strchr(char *s, int c);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096

# endif
#endif
