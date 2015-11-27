/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/31 19:27:18 by fklein            #+#    #+#             */
/*   Updated: 2015/11/01 19:05:53 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int		simple_atoi(char *str)
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
