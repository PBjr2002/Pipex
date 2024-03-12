/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:51:05 by pauberna          #+#    #+#             */
/*   Updated: 2023/10/06 11:39:20 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *)s;
	while (*ptr)
	{
		if (*ptr == (char)c)
			return (ptr);
		ptr++;
	}
	if ((char)c == 0)
		return (ptr);
	return (NULL);
}

/*int	main(void)
{
	char	*str = "Algo de errado nao esta certo";
	char	c = 'z';

	if (ft_strchr(str, c) == NULL && strchr(str, c) == NULL)
		printf("NULL\n");
	else
	{
		printf("%s\n", ft_strchr(str, c));
		printf("%s\n", strchr(str, c));
	}
	return (0);
}*/
