/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:16:42 by pbjr              #+#    #+#             */
/*   Updated: 2023/09/13 18:07:01 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) == 1)
	{
		return (1);
	}
	else if (ft_isdigit(c) == 1)
	{
		return (1);
	}
	return (0);
}

/*int main(void)
{
	ft_putnbr_fd(ft_isalnum('0'), 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(ft_isalnum('A'), 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(ft_isalnum('z'), 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(ft_isalnum('9'), 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(ft_isalnum('\n'), 1);
	ft_putchar_fd('\n', 1);
	return (0);
}*/
