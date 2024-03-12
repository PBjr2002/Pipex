/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:34:38 by pauberna          #+#    #+#             */
/*   Updated: 2023/10/06 14:48:52 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*p;

	p = s;
	while (n != 0)
	{
		*p = 0;
		p++;
		n--;
	}
}

/*int	main(void)
{
	void	*str[20];
	void	*str2[20];

	memset(str, 67, 20);
	memset(str2, 67, 20);
	printf("%s\n", (unsigned char *)str);
	printf("%s\n", (unsigned char *)str2);
	ft_bzero(str, 20);
	ft_bzero(str2, 20);
	printf("%s\n", (unsigned char *)str);
	printf("%s\n", (unsigned char *)str2);
	printf("%d\n",memcmp(str, str2, 20));
	return (0);
}*/
