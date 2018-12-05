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

//#include "/Users/lmaron-g/libft/libft.h"
#include "/home/marshtupa/libft/libft.h"
#include "get_next_line.h"
#include <stdio.h>

int				ft_strjoint(char **dest, char *src)
{
	char		*ret;
	char		*fresh;
	char		*dst;

	ret = 0;
	dst = *dest;
	if (dst && src && (fresh = ft_strnew(ft_strlen(dst) + ft_strlen(src))))
	{
		ret = fresh;
		while (*dst)
			*fresh++ = (char)*dst++;
		while (*src)
			*fresh++ = (char)*src++;
	}
	else
		return (0);
	free(*dest);
	*dest = ret;
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
	while ((bytes = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[bytes] = 0;
		if (!(ft_strjoint(&fresh, buf)))
			return (-1);
		if (ft_strchr(buf, '\n'))
			break;
	}
	if (bytes < BUFF_SIZE && !(ft_strlen(fresh)))
		return (0);
	*line = ft_strsub(fresh, 0, (ft_strchr(fresh, '\n') - fresh));
	fresh = ft_strdup(ft_strchr(fresh, '\n') + 1);
	return (1);
}

int main()
{
	char	*output1;
	char	file1[] = "get_next_line.h";
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
