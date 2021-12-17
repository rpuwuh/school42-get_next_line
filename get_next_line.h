/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:44:04 by bpoetess          #+#    #+#             */
/*   Updated: 2021/12/17 12:25:54 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE 
# 	define BUFFER_SIZE 42 
# endif

# define MAX_BUFFER 127

# include <stdlib.h>
# include <unistd.h>

size_t		ft_strlen(const char	*s);

char		*ft_strchr(const char *s, int c);

char		*ft_strjoin(char const *s1, char const *s2);

size_t		ft_strchr_num(char *s, char c);

char		*ft_splitnewline(char *buf, char *tail);

void		ft_cleartail(char *s, size_t i);

char		*get_next_line(int fd);

#endif
