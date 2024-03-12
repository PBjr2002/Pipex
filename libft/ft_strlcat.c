/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:05:25 by pauberna          #+#    #+#             */
/*   Updated: 2023/10/06 10:27:08 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	n;
	size_t	i;
	char	*ptr;

	ptr = (char *)src;
	n = 0;
	while (n < size && *dst)
	{
		dst++;
		n++;
	}
	if (n == size)
		return (n + ft_strlen(src));
	i = 0;
	while (ptr[i] != '\0')
	{
		if (i < size - n - 1)
			*dst++ = ptr[i];
		i++;
	}
	*dst = 0;
	return (n + i);
}

/*int	main(void)
{
	char	dest[10000] = "nem me vais ver!";
	char	src[] = "nem a mim, mas vais saber o nosso tamanho!";
	printf("%ld\n",ft_strlcat(dest, src, 50));
	printf("%s\n", dest);
	return (0);
}*/
