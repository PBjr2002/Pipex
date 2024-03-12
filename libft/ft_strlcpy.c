/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:39:00 by pauberna          #+#    #+#             */
/*   Updated: 2023/10/04 15:29:23 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	n;

	if (size == 0)
		return (ft_strlen(src));
	n = 0;
	while (src[n] != '\0' && n < (size - 1))
	{
		dst[n] = src[n];
		n++;
	}
	dst[n] = '\0';
	return (ft_strlen(src));
}

/*int	main(void)
{
	char	dest[] = "nem me vais ver!";
	char	src[] = "nem a mim, mas vais saber o nosso tamanho!";
	ft_putnbr_fd(ft_strlcpy(dest, src, 20), 1);
	ft_putchar_fd('\n', 1);
	return (0);
}*/
