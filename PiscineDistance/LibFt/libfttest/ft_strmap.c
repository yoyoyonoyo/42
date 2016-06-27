/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 14:08:22 by fklein            #+#    #+#             */
/*   Updated: 2016/03/21 14:08:26 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*t;
	int		i;

	i = 0;
	t = ft_strnew(ft_strlen(s));
	while (s[i] != 0)
	{
		t[i] = f(s[i]);
		i++;
	}
	return (t);
}
