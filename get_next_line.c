/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 20:34:05 by lmaron-g          #+#    #+#             */
/*   Updated: 2018/12/02 20:34:07 by lmaron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/lmaron-g/libft/libft.h"
#include "get_next_line.h"
#include <stdio.h>

int				ft_strjoint(char **s11, char *s2)
{
	char		*ret;
	char		*fresh;
	char		*s1;

	ret = 0;
	s1 = *s11;
	if (s1 && s2 && (fresh = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
	{
		ret = fresh;
		while (*s1)
			*fresh++ = (char)*s1++;
		while (*s2 && *s2 != '\n')
			*fresh++ = (char)*s2++;
	}
	else
		return (0);
	free(*s11);
	*s11 = ret;
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	int			bytes;
	static char	*fresh;
	char		buf[BUFF_SIZE + 1];

	bytes = 0;
	if (!fresh)
		fresh = ft_strnew(0);
	if (!(ft_strchr(fresh, '\n')))
	{
		while ((bytes = read(fd, buf, BUFF_SIZE)))
		{
			buf[bytes] = 0;
			if (!(ft_strjoint(&fresh, buf)))
				return (-1);
			if (ft_strchr(buf, '\n'))
				break;
		}
		if (bytes < BUFF_SIZE && !ft_strlen(fresh))
			return (0);
		*line = fresh;
		fresh = ft_strdup(ft_strchr(buf, '\n') + 1);
	} else
		{
			free(*line);
			*line = ft_strsub(fresh, 0, ft_strchr(fresh, '\n') - fresh);
			fresh = ft_strdup(ft_strchr(fresh, '\n') + 1);
		}
	return (1);
}

int main()
{
	char	*output1;
	char	file1[] = "text1";
	int		fd1 = open(file1, O_RDONLY);
	int		n = 4;

	while (n)
	{
		get_next_line(fd1, &output1);
		printf("%s\n", output1);
		n--;
	}
	close(fd1);
	return 0;
}
