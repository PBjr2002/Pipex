/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:49:02 by pbjr              #+#    #+#             */
/*   Updated: 2023/10/10 15:38:07 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*string;

	string = (char *)s;
	i = 0;
	while (i < n)
	{
		string[i] = c;
		i++;
	}
	return (s);
}

/*int main(void)
{
	char	str[] = "Tem memoria que chegue ?";
	char	c = 'u';
	ft_putstr_fd(ft_memset(str, c, 25), 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd(memset(str, c, 25), 1);
	ft_putchar_fd('\n', 1);
	return (0);
}*/
