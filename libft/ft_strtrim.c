/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:13:31 by pauberna          #+#    #+#             */
/*   Updated: 2023/10/13 14:40:27 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		n;
	int		i;

	if (set == NULL)
		return (ft_strdup(s1));
	n = 0;
	i = ft_strlen(s1);
	while (s1[n] && ft_strchr(set, s1[n]))
		n++;
	while (i > n && ft_strchr(set, s1[i]))
		i--;
	str = ft_substr(s1, n, i - n + 1);
	if (str == NULL)
		return (NULL);
	return (str);
}

/*int		main(void)
{
	char	*str;
	char	*str1;
	char	*str2;

	str = "cab ola pessoas abc";
	str1 = "abc";
	str2 = ft_strtrim(str, str1);
	printf("%s\n", str2);
	free(str2);
	return (0);
}*/
