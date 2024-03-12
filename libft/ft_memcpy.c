/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:54:29 by pauberna          #+#    #+#             */
/*   Updated: 2023/10/11 14:25:36 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = dest;
	s = src;
	while (n > 0)
	{
		*d = *s;
		d++;
		s++;
		n--;
	}
	return (dest);
}

/*int main(void)
{
	char	str[] = "Esta string vai ser copiada eheh";
	char	dest[33];

	ft_putstr_fd(ft_memcpy(dest, str, 33), 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd(memcpy(dest,str, 33), 1);
	ft_putchar_fd('\n', 1);
	return (0);
}*/
