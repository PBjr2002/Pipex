/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:37:38 by pauberna          #+#    #+#             */
/*   Updated: 2023/10/09 13:44:36 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

/*int	main(void)
{
	t_list	*new;
	t_list	*new1;
	t_list	*last;
	
	new = ft_lstnew("aquilo");
	new1 = ft_lstnew("isto");
	ft_lstadd_back(&new, new1);
	last = ft_lstlast(new);
	printf("%s\n", (char *)last->content);
	return (0);
}*/
