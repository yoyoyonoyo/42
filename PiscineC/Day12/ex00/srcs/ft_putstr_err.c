/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 13:40:30 by flklein           #+#    #+#             */
/*   Updated: 2018/09/17 13:42:10 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_display_file.h"

void	ft_putstr_err(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		ft_putchar_err(str[i++]);
}
