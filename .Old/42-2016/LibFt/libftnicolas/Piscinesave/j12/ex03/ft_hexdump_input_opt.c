/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump_input_opt.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 12:22:33 by nthibaud          #+#    #+#             */
/*   Updated: 2016/04/06 12:42:04 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	read_and_stock_inopt(char *tab, int *count_valid, int *char_nb)
{
	char	buf[2];
	char	prev_tab[17];
	int		identical;

	identical = 0;
	while (read(0, buf, 1))
	{
		tab[count_valid[0]] = buf[0];
		count_valid[0]++;
		if (count_valid[0] == 16)
		{
			tab[16] = '\0';
			prev_tab[16] = '\0';
			if (ft_strcmp(tab, prev_tab) == 0)
				tab_cmp(count_valid, char_nb, &identical);
			else
			{
				identical = 0;
				display_inopt(tab, count_valid, char_nb);
			}
			ft_strcpy(tab, prev_tab);
			count_valid[0] = 0;
		}
	}
}

int		ft_hexdump_inopt(int option_nb)
{
	int		char_nb;
	int		count_valid[3];
	char	tab[17];

	char_nb = 0;
	init_count_valid_opt(count_valid, option_nb);
	read_and_stock_inopt(tab, count_valid, &char_nb);
	return (0);
}