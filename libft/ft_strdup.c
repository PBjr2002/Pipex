/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:11:58 by pauberna          #+#    #+#             */
/*   Updated: 2023/10/06 16:03:27 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	len;

	len = ft_strlen(s) + 1;
	str = malloc (len);
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, s, len);
	return (str);
}

/*int	main(void)
{
	char	*str = "Esta string vai ser duplicada eheh";
	char	*str1;
	char	*str2;
	
	str1 = ft_strdup(str);
	str2 = strdup(str);
	printf("%s\n", str1);
	printf("%s\n", str2);
	free(str1);
	free(str2);
	return (0);
}*/
