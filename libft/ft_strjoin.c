/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:46:24 by pauberna          #+#    #+#             */
/*   Updated: 2024/03/11 11:20:37 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		len;
	int		n;
	int		i;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	ptr = (char *)malloc (sizeof(char) * len);
	if (ptr == NULL)
		return (NULL);
	n = 0;
	while (s1[n])
	{
		ptr[n] = s1[n];
		n++;
	}
	i = 0;
	while (s2[i])
	{
		ptr[n] = s2[i];
		n++;
		i++;
	}
	ptr[n] = '\0';
	return (ptr);
}

/*int	main(void)
{
	char	*str;
	char	*str1;
	char	*str2;

	str = "esta string vai ser colada";
	str1 = "com esta string";
	str2 = ft_strjoin(str, str1);
	printf("%s\n", str2);
	free(str2);
	return (0);
}*/
