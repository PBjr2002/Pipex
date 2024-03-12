/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:11:02 by pauberna          #+#    #+#             */
/*   Updated: 2023/10/09 11:34:17 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const	*s, char (*f)(unsigned int, char))
{
	char	*str;
	int		n;

	if (s == NULL)
		return (ft_strdup(""));
	str = ft_strdup(s);
	if (str == NULL)
		return (NULL);
	n = 0;
	while (s[n] != '\0')
	{
		str[n] = (*f)(n, str[n]);
		n++;
	}
	str[n] = '\0';
	return (str);
}

/*char	ft_test(unsigned int i, char s)
{
	i = 1;
	s += i;
	return (s);
}

int	main(void)
{
	char	*str = "vou usar o ft_test nesta frase";
	printf("%s\n", ft_strmapi(str, &ft_test));
	return (0);
}*/
