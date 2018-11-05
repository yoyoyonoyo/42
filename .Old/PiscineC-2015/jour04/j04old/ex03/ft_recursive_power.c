/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <fklein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/20 14:28:33 by fklein            #+#    #+#             */
/*   Updated: 2015/10/20 14:38:13 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_power(int nb, int power)
{
	if (power == -1)
		return (0);
	if (power == 0)
		return (1);
	nb = nb * ft_recursive_power(nb, power - 1);
	return (nb);
}