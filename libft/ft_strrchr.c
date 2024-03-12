/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:37:23 by pauberna          #+#    #+#             */
/*   Updated: 2023/10/06 11:53:52 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;

	ptr = NULL;
	while (*s)
	{
		if (*s == (char)c)
			ptr = (char *)s;
		s++;
	}
	if ((char)c == 0)
		return ((char *)s);
	return (ptr);
}

/*int	main(void)
{
	char	*str = "Algo de errado nao esta certo";
	char	c = '\0';

	if (ft_strrchr(str, c) == NULL && strrchr(str, c) == NULL)
		printf("NULL\n");
	else
	{
		printf("%s\n", ft_strrchr(str, c));
		printf("%s\n", strrchr(str, c));
	}
	return (0);
}*/
