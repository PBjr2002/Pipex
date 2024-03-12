/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:47:00 by pauberna          #+#    #+#             */
/*   Updated: 2023/10/06 15:57:39 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	n;

	if (start > ft_strlen(s))
		len = 0;
	else if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	n = 0;
	while (s[n] != '\0' && (n < len))
	{
		str[n] = s[n + start];
		n++;
	}
	str[n] = '\0';
	return (str);
}

/*int	main(void)
{
	char	*str = "esta string pode ser cortada ou nao";
	char	*str1 = ft_substr(str, 32, 3);
	printf("%s\n", str1);
	free(str1);
	return (0);
}*/
