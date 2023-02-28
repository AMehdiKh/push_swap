/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khel <ael-khel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:29:42 by ael-khel          #+#    #+#             */
/*   Updated: 2023/02/27 18:42:25 by ael-khel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*ft_strjoin_gnl(char **reserve, char *buffer);
char	*ft_check_nl(char **reserve);
char	*ft_strdup_gnl(char **reserve);
char	*get_next_line(int fd);

void	ft_strlcpy_gnl(char *dst, const char *src, size_t size);

void	*ft_free(char **ptr1);

size_t	ft_strlen_gnl(const char *s);

int		ft_strchr_gnl(char *s, int c);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

#endif