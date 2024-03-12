/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:53:20 by pauberna          #+#    #+#             */
/*   Updated: 2024/02/27 15:51:42 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	ptr;
	int		n;
	int		i;

	n = 0;
	i = 0;
	if (!little || len == 0)
		return (NULL);
	ptr = ft_strlen(little);
	if (little[0] == '\0')
		return ((char *)big);
	while (big[n] != '\0' && ptr <= len)
	{
		i = 0;
		while (big [n + i] == little[i] && big[n + i] != '\0')
		{
			i++;
			if (little[i] == '\0')
				return ((char *)big + n);
		}
		n++;
		ptr++;
	}
	return (NULL);
}

/*int	main(void)
{
	char	*fds;
	fds = ft_strnstr("12345678palavra", "palavra", 10);
	
	printf("%p\n", fds);
	return (0);
}*/
