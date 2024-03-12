/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:23:47 by pauberna          #+#    #+#             */
/*   Updated: 2024/01/30 15:09:12 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int x, int y)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->x = x;
	new->y = y;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

/*int	main(void)
{
	t_list	*new;
	new = ft_lstnew("ola");
	printf("%s\n", (char *)new->content);
	return (0);
}*/
