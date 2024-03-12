/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:06:19 by pauberna          #+#    #+#             */
/*   Updated: 2023/10/09 10:16:46 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	get_len(int number, int len)
{
	if (number <= 0)
		len++;
	while (number != 0)
	{
		len++;
		number = number / 10;
	}
	return (len);
}

static	char	*set_num(char *number, int len, int digits, int n)
{
	if (n == -2147483648)
	{
		number[0] = '-';
		number[1] = '2';
		n = 147483648;
		digits = 2;
	}
	if (n < 0)
	{
		number[0] = '-';
		digits = 1;
		n = -n;
	}
	number[len] = '\0';
	while (len > digits)
	{
		number[len - 1] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	return (number);
}

char	*ft_itoa(int n)
{
	char	*num;
	int		len;
	int		digits;

	digits = 0;
	len = 0;
	len = get_len(n, len);
	num = malloc(sizeof(char) * (len + 1));
	if (num == NULL)
		return (NULL);
	num = set_num(num, len, digits, n);
	return (num);
}

/*int	main(void)
{
	int	num = -2147483648;
	printf("%s\n", ft_itoa(num));
	return (0);
}*/
