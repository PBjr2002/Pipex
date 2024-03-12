/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:03:19 by pauberna          #+#    #+#             */
/*   Updated: 2023/10/06 10:33:00 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}

/*int	main(void)
{
	ft_putchar_fd(ft_toupper('a'), 1);
	ft_putchar_fd('\n', 1);
	ft_putchar_fd(ft_toupper('Z'), 1);
	ft_putchar_fd('\n', 1);
	ft_putchar_fd(ft_toupper('9'), 1);
	ft_putchar_fd('\n', 1);
	return (0);
}*/
