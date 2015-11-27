/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/24 16:16:57 by fklein            #+#    #+#             */
/*   Updated: 2015/10/27 21:07:56 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	while (*(str++))
		ft_putchar(*(str - 1));
}

int		main(int argc, char **argv)
{
	int index;

	index = argc - 1;
	if (argc == 1)
		return (0);
	else
		while (index != 0)
		{
			ft_putstr(argv[index]);
			ft_putchar('\n');
			index--;
		}
	return (0);
}
