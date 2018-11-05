/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 14:54:46 by flklein           #+#    #+#             */
/*   Updated: 2018/11/05 14:54:49 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_if(char **tab, int (*f)(char *))
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (tab[i])
	{
		if ((*f)(tab[i]))
			count++;
		i++;
	}
	return (count);
}