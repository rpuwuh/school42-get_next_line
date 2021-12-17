/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:37:02 by bpoetess          #+#    #+#             */
/*   Updated: 2021/12/17 12:28:35 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strchr_num(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s && s[i] && s[i] != c)
		i++;
	return (i);
}

char	*ft_splitnewline(char *buf, char *tail)
{
	size_t	i;
	size_t	len;
	char	*res;

	i = 0;
	len = ft_strchr_num(buf, '\n');
	res = (char *) malloc (len + 2);
	if (!res)
		return (0);
	while (i <= len)
	{
		res [i] = buf [i];
		i++;
	}
	res [i] = '\0';
	while (buf[i])
	{
		tail[i - len - 1] = buf [i];
		i++;
	}
	if (!buf[len])
		ft_cleartail(tail, 0);
	ft_cleartail(tail, i - len - 1);
	return (res);
}

void	ft_cleartail(char *s, size_t i)
{
	while (i <= BUFFER_SIZE)
		s[i++] = '\0';
}

char	*ft_get_next_buffer(size_t *readc, char *s, char *tail, int fd)
{
	char	*temp;

	*readc = read (fd, tail, BUFFER_SIZE);
	if (!*readc && !s[0])
	{
		free (s);
		return (0);
	}
	ft_cleartail(tail, *readc);
	temp = s;
	s = ft_strjoin(temp, tail);
	free(temp);
	return (s);
}

char	*get_next_line(int fd)
{
	static char		tail [BUFFER_SIZE + 1];
	char			*s;
	char			*temp;
	size_t			readcount;

	if (BUFFER_SIZE < 1 || fd < 0 || fd > MAX_BUFFER || fd == 3)
		return (0);
	tail [BUFFER_SIZE] = '\0';
	if (ft_strchr(tail, '\n'))
		return (ft_splitnewline(tail, tail));
	s = ft_strjoin (tail, "");
	readcount = BUFFER_SIZE;
	while (readcount && !ft_strchr(s, '\n'))
	{
		s = ft_get_next_buffer(&readcount, s, tail, fd);
		if (!s)
			return (0);
	}
	temp = s;
	s = ft_splitnewline(temp, tail);
	free(temp);
	return (s);
}
