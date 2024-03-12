/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:20:25 by pauberna          #+#    #+#             */
/*   Updated: 2024/01/26 12:44:39 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, int (*f)(int), void (*del)(int))
{
	t_list	*new_lst;
	t_list	*new_node;

	new_lst = NULL;
	while (lst != NULL)
	{
		new_node = (t_list *)malloc(sizeof(t_list));
		if (new_node == NULL)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		new_node->x = (*f)(lst->x);
		new_node->y = (*f)(lst->y);
		new_node->next = NULL;
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}

/*void	*function(void *content)
{
	char	*str;
	char	*original = (char *)content;

	str = (char *)malloc(ft_strlen(original) + 4);
	ft_strlcpy(str, original, ft_strlen(original) + 1);
	ft_strlcat(str, "abc",ft_strlen(original) + 4);
	return (str);
}

void	del(void *content)
{
	content = NULL;
}

int	main(void)
{
	t_list	*new;
	t_list	*new1;
	t_list	*new2;
	t_list	*final_lst;
	
	new = ft_lstnew("isto n e suposto ser mexido");
	new1 = ft_lstnew("mas isto e");
	new2 = ft_lstnew("isto tambem");
	ft_lstadd_back(&new, new1);
	ft_lstadd_back(&new, new2);
	final_lst = ft_lstmap(new, function, del);
	printf("%s\n", (char *)final_lst->content);
	printf("%s\n", (char *)final_lst->next->content);
	printf("%s\n", (char *)final_lst->next->next->content);
	printf("%s\n", (char *)final_lst->next->next->next);
	while (final_lst->next != NULL)
	{
		free(final_lst->content);
		final_lst = final_lst ->next;
	}
	return (0);
}*/
