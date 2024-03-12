/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 15:46:13 by pbjr              #+#    #+#             */
/*   Updated: 2023/10/04 14:04:23 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

/*int main(void)
{
	ft_putnbr_fd(ft_isdigit('0'), 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(ft_isdigit('9'), 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(ft_isdigit('a'), 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(ft_isdigit('\n'), 1);
	ft_putchar_fd('\n', 1);
	return (0);
}*/
