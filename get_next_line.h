/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:44:04 by bpoetess          #+#    #+#             */
/*   Updated: 2022/01/02 17:57:41 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef MAX_BUFFER
#  define MAX_BUFFER 255
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

size_t		ft_strlen(const char	*s);
char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_gnl_buffer(ssize_t *readc, int fd, char **str_p);
char		*ft_substr(char *s, unsigned int start, size_t len);

char		*ft_gnl_trim(ssize_t readc, char **tail_p, char **str_p);
void		ft_cleanfreestring(char **s);
char		*get_next_line(int fd);
char		*ft_newstring(void);

#endif