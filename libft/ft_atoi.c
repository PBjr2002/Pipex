/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:26:01 by pauberna          #+#    #+#             */
/*   Updated: 2023/09/15 15:38:39 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	n;
	int	result;
	int	signal;

	n = 0;
	result = 0;
	signal = 1;
	while ((nptr[n] >= 9 && nptr[n] <= 13) || nptr[n] == 32)
		n++;
	if (nptr[n] == '+' || nptr[n] == '-')
	{
		if (nptr[n] == '-')
			signal = -signal;
		n++;
	}
	while (nptr[n] >= '0' && nptr[n] <= '9')
	{
		result = (result * 10) + (nptr[n] - 48);
		n++;
	}
	return (result * signal);
}

/*int main(void)
{
	char str[] = "	-12347777777777777777abc";
	printf ("%d\n", ft_atoi(str));
	printf ("%d\n", atoi(str));
	return (0);
}*/
