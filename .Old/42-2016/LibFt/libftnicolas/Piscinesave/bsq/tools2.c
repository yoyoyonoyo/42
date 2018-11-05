/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <fklein@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 18:29:26 by fklein            #+#    #+#             */
/*   Updated: 2016/04/20 18:29:45 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		ft_check_eol(int i, int n, char *s)
{
	if (i == n - 1)
	{
		*(s + i + 1) = '\0';
		return (1);
	}
	else
		return (0);
}

void	ft_run_bsq(char **map, t_map *map_info)
{
	map_info->width--;
	map_info->height--;
	ft_bsq(map, map_info);
	ft_print_map(map, PRINT_SPACES);
	free(map);
}

int		ft_strf(char c, char *s)
{
	while (c != *s && *s)
		(s++);
	return ((c == *s) ? 0 : 1);
}

int		i_am_number(int i, char *str)
{
	long	nbr;
	int		j;
	int		out;

	out = 0;
	nbr = 0;
	j = i;
	if (str[i] == '-' || str[i] == '+')
		j = i + 1;
	while (str[j] >= '0' && str[j] <= '9')
	{
		nbr += str[j] - '0';
		nbr *= 10;
		j++;
	}
	if (str[i] == '-')
		nbr = -nbr;
	if (nbr / 2147483647 >= 1)
		out = (nbr / 10) % 4294967296 - 4294967296;
	else
		out = nbr / 10;
	return (out);
}

int		ft_atoi(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') || (str[i] == '-' &&
					str[i + 1] >= '0' && str[i + 1] <= '9') || (str[i] == '+' &&
						str[i + 1] >= '0' && str[i + 1] <= '9'))
			return (i_am_number(i, &str[0]));
		if (str[i] != ' ' && str[i] != 9 && str[i] != 10)
			return (0);
		else
			i++;
	}
	return (0);
}