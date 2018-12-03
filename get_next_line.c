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
#include <stdlib.h>
#include <stdio.h>

int			get_next_line(const int fd, char **line)
{
	int		bytes;
	static char	*fresh;
	char	buf[BUFF_SIZE + 1];

	bytes = 0;
	if (!fresh)
		fresh = ft_strnew(0);
	while ((bytes = read(fd, buf, BUFF_SIZE)))
	{
		buf[bytes] = 0;
		if (!(fresh = ft_strjoin(fresh, buf)))
			return (-1);
		if (ft_strchr(buf, '\n'))
			break;
	}
	*line = fresh;
	return (1);
}

int main()
{
	char	*output;
	char	file[] = "get_next_line.h";
	int		fd = open(file, O_RDONLY);
	int		n = 5;

	printf("file is = %s\n", file);
	printf("fd is = %d\n", fd);

	while (n--)
	{
		get_next_line(fd, &output);
		printf("Output is = \n%s\n", output);
	}
	close(fd);
	return 0;
}
