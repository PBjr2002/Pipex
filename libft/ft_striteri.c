/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:10:06 by pauberna          #+#    #+#             */
/*   Updated: 2023/10/20 15:35:54 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	n;

	n = 0;
	while (s[n] != '\0')
	{
		(*f)(n, s + n);
		n++;
	}
	s[n] = '\0';
}

/*void	ft_test(unsigned int i, char *s)
{
	i = 1;
	*s += i;
}

int	main(void)
{
	char	str[] = "vou usar o ft_test nesta string";
	ft_striteri(str, ft_test);
	printf("%s\n", str);
	return (0);
}*/
