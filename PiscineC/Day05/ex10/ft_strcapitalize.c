/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 00:13:53 by flklein           #+#    #+#             */
/*   Updated: 2018/09/02 02:07:27 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z'
				&& (!str[i - 1] || (i > 0 && str[i - 1]
						&& !(str[i - 1] >= 'a' && str[i - 1] <= 'z')
						&& !(str[i - 1] >= 'A' && str[i - 1] <= 'Z')
						&& !(str[i - 1] >= '0' && str[i - 1] <= '9'))))
			str[i] -= 32;
		else
		{
			if (str[i] >= 'A' && str[i] <= 'Z'
					&& ((str[i - 1] >= 'a' && str[i - 1] <= 'z')
						|| (str[i - 1] >= 'A' && str[i - 1] <= 'Z')
						|| (str[i - 1] >= '0' && str[i - 1] <= '9')))
				str[i] += 32;
		}
		i++;
	}
	return (str);
}
