/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 01:27:29 by flklein           #+#    #+#             */
/*   Updated: 2018/08/31 12:24:11 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		nb = 147483648;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}

int		puissance(int n, int p)
{
	if (p > 0)
		return (n * puissance(n, p - 1));
	else
		return (1);
}

int		is_croissant(int nb)
{
	if (nb < 10)
		return (1);
	else if (nb % 10 > (nb / 10) % 10)
		return (is_croissant(nb / 10));
	else
		return (0);
}

void	ft_print_combn(int n)
{
	int		i;
	int		s;
	int		p;

	i = puissance(10, n - 2) - 1;
	p = puissance(10, n);
	while (i++ < p && i <= 123456789 && n)
	{
		if (is_croissant(i))
		{
			if (s)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			s = i;
			while (s < puissance(10, n - 1))
			{
				ft_putchar('0');
				s = s * 10;
			}
			ft_putnbr(i);
		}
	}
}

int		main()
{
	//	printf("%d\n", is_croissant(1));
	//	printf("%d\n", is_croissant(10));
	//	printf("%d\n", is_croissant(123));
	ft_print_combn(9);
}