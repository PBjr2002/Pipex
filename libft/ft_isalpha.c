/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 15:44:13 by pbjr              #+#    #+#             */
/*   Updated: 2023/10/04 15:05:29 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
	{
		return (1);
	}
	return (0);
}

/*int	main(void)
{
	ft_putnbr_fd(ft_isalpha('A'), 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(ft_isalpha('z'), 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(ft_isalpha('5'), 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(ft_isalpha('\n'), 1);
	ft_putchar_fd('\n', 1);
	return (0);
}*/
