/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:32:48 by pbjr              #+#    #+#             */
/*   Updated: 2023/09/12 19:26:56 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
	{
		return (1);
	}
	return (0);
}

/*int	main(void)
{
	ft_putnbr_fd(ft_isascii(-1), 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(ft_isascii(0), 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(ft_isascii(127), 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(ft_isascii(134), 1);
	ft_putchar_fd('\n', 1);
	return (0);
}*/
