/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <flklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:19:18 by flklein           #+#    #+#             */
/*   Updated: 2018/11/08 16:17:40 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	unsigned long	nb;
	int				sign;

	nb = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
		sign *= (*(str++) == '-' ? -1 : 1);
	while (*str >= '0' && *str <= '9')
		nb = nb * 10 + *(str++) - '0';
	if (nb > 4294967295)
		return (sign == 1 ? -1 : 0);
	return (sign * nb);
}
