/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 12:58:24 by lmaron-g          #+#    #+#             */
/*   Updated: 2018/11/22 12:58:30 by lmaron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*area;

	if (size > size + 1)
		return (0);
	if (!(area = (char*)malloc(size + 1)))
		return (0);
	ft_memset(area, (int)'\0', size + 1);
	return (area);
}
