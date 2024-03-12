/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:37:23 by pauberna          #+#    #+#             */
/*   Updated: 2023/10/10 14:53:08 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*ptr;

	ptr = (char *)s;
	c = (char)c;
	while (n != 0 && *ptr != c)
	{
		ptr++;
		n--;
	}
	if (n != 0)
		return ((void *)ptr);
	else
		return (NULL);
}

/*int	main(void)
{
	char *str = "Quando encontrares . segue!";
	char c = '.';
	printf("%p\n",ft_memchr(str, c, ft_strlen(str)));
	printf("%p\n",memchr(str, c, ft_strlen(str)));
	return (0);
}*/
