/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:14:02 by pauberna          #+#    #+#             */
/*   Updated: 2024/03/21 14:31:33 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	n;

	n = 0;
	while (s && s[n] != '\0')
	{
		write(fd, &s[n], 1);
		n++;
	}
	write(fd, "\n", 1);
}

/*int	main(void)
{
	char	*str = "esta string vai ser imprimida mas com um \\n";
	ft_putendl_fd(str, 1);
	return (0);
}*/
