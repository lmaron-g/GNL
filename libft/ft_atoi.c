/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 22:04:37 by lmaron-g          #+#    #+#             */
/*   Updated: 2018/11/21 22:04:39 by lmaron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define A(c) (c == ' ')
#define B(c) (c == '\n')
#define C(c) (c == '\t')
#define D(c) (c == '\v')
#define I(c) (c == '\f')
#define F(c) (c == '\r')

#define SP(c) (A(c) || B(c) || C(c) || D(c) || I(c) || F(c))

#include "libft.h"

int					ft_atoi(const char *str)
{
	int				neg;
	int				i;
	long long int	num;
	long long int	temp;

	i = 0;
	neg = 0;
	num = 0;
	while (SP(str[i]))
		i++;
	if (str[i] == 45)
		neg = 1;
	if ((str[i] == 45) || (str[i] == 43))
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		temp = num;
		num *= 10;
		num += ((int)str[i] - 48);
		if (num < temp)
			return (neg == 1 ? 0 : -1);
		i++;
	}
	return (neg == 1 ? -num : num);
}
