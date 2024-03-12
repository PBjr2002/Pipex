/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:36:31 by pauberna          #+#    #+#             */
/*   Updated: 2024/01/10 11:13:09 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(char	*str_to_srch, char	*str_to_cmp)
{
	int	n;

	n = 0;
	while (str_to_srch[n] || str_to_cmp[n])
	{
		if (str_to_srch[n] != str_to_cmp[n])
		{
			return (str_to_srch[n] - str_to_cmp[n]);
		}
		n++;
	}
	return (0);
}
