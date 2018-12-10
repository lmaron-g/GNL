/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 12:54:42 by lmaron-g          #+#    #+#             */
/*   Updated: 2018/11/22 12:54:45 by lmaron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define SIZE_T_MAX 65535

void		*ft_memalloc(size_t size)
{
	void	*area;

	if (!(area = malloc(size)))
		return (0);
	if (size == SIZE_T_MAX)
		size--;
	ft_memset(area, 0, size);
	return (area);
}
