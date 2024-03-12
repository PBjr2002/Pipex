/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:07:15 by pauberna          #+#    #+#             */
/*   Updated: 2023/10/04 17:37:22 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	n;

	n = 0;
	while (s[n] != '\0')
	{
		write(fd, &s[n], 1);
		n++;
	}
}

/*int	main(void)
{
	char	*str = "esta string vai ser imprimida no total\n";
	ft_putstr_fd(str, 1);
	return (0);
}*/
