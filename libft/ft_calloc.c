/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:47:21 by pauberna          #+#    #+#             */
/*   Updated: 2024/02/14 15:03:21 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*aux;

	aux = malloc(nmemb * size);
	if (!aux)
		return (NULL);
	ft_bzero(aux, nmemb * size);
	return (aux);
}

/*int	main(void)
{
	char	*str;
	char	*str1;

	str = (char *)ft_calloc(10, sizeof(char));
	str1 = (char *)calloc(10, sizeof(char));
	if (str1 != NULL)
		printf("calloc deu\n");
	else
		printf("calloc falhou\n");
	if (str != NULL)
		printf("ft_calloc funcionou\n");
	else
		printf("ft_calloc falhou\n");
	free(str);
	free(str1);
	return (0);
}*/
