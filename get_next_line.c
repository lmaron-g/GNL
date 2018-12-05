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

#include "libft.h"
#include "get_next_line.h"

int					ft_cat_pro(char **dest, char *src)
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
	ft_strdel(dest);
	*dest = ret;
	return (1);
}

t_file				*find_node(t_file **list, int fd)
{
	t_file			*temp;

	if (!list)
		return (0);
	temp = *list;
	while (temp)
	{
		if (temp->fd == fd)
			return (temp);
		temp = temp->next;
	}
	if (!(temp = (t_file*)malloc(sizeof(t_file))))
		return (0);
	if (!(temp->s = ft_strnew(0)))
		return (0);
	temp->fd = fd;
	temp->next = *list;
	*list = temp;
	return (temp);
}

char				*out_manage(char **sours)
{
	char			*res;
	char			*temp;
	size_t			i;

	i = 0;
	if (!(temp = ft_strdup(*sours)))
		return (0);
	while (temp[i] != '\n' && temp[i])
		i++;
	if (!(res = ft_strsub(*sours, 0, i)))
		return (0);
	ft_strdel(sours);
	if (ft_strchr(temp, '\n'))
	{
		if (!(*sours = ft_strdup(temp + i + 1)))
			return (0);
	}
	else if (!(*sours = ft_strnew(0)))
		return (0);
	ft_strdel(&temp);
	return (res);
}

int					get_next_line(const int fd, char **line)
{
	int				bytes;
	static t_file	*list;
	t_file			*tmp;
	char			buf[BUFF_SIZE + 1];

	if (fd < 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	if (!(tmp = find_node(&list, fd)))
		return (-1);
	while ((bytes = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[bytes] = 0;
		if (!(ft_cat_pro(&(tmp->s), buf)))
			return (-1);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (bytes < BUFF_SIZE && !(ft_strlen(tmp->s)))
		return (0);
	if (!(*line = out_manage(&tmp->s)))
		return (-1);
	return (1);
}
