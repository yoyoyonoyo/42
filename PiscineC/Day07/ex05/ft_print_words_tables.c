/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_words_tables.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 14:47:03 by flklein           #+#    #+#             */
/*   Updated: 2018/09/06 14:36:57 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*(str++));
}

void	ft_print_words_tables(char **tab)
{
	int		p;

	p = 0;
	while (tab[p])
	{
		ft_putstr(tab[p]);
		ft_putchar('\n');
		p++;
	}
}
