/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:56:16 by pauberna          #+#    #+#             */
/*   Updated: 2024/01/26 12:42:02 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(int))
{
	t_list	*node;
	t_list	*next_node;

	if (lst == NULL)
		return ;
	node = *lst;
	while (node != NULL)
	{
		next_node = node->next;
		del(node->x);
		del(node->y);
		free(node);
		node = next_node;
	}
	*lst = NULL;
}

/*void	del(void *content)
{
	content = NULL;
}

int	main(void)
{
	t_list	*new;
	t_list	*new1;
	t_list	*new2;
	
	new = ft_lstnew("isto n e suposto desaparecer");
	new1 = ft_lstnew("mas isto e");
	new2 = ft_lstnew("isto tambem");
	ft_lstadd_back(&new, new1);
	ft_lstadd_back(&new1, new2);
	ft_lstclear(&new1, del);
	printf("%s\n", (char *)new->next->content);
	return (0);
}*/
