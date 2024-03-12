/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:00:25 by pauberna          #+#    #+#             */
/*   Updated: 2024/01/26 12:41:14 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(int))
{
	if (lst == NULL)
		return ;
	del(lst->x);
	del(lst->y);
	free(lst);
}

/*void	del(void *content)
{
	content = NULL;
}

int	main(void)
{
	t_list	*new;
	t_list	*new1;
	
	new = ft_lstnew("isto n e suposto desaparecer");
	new1 = ft_lstnew("mas isto e");
	ft_lstadd_back(&new, new1);
	ft_lstdelone(new1, del);
	printf("%s\n", (char *)new->next->content);
	return (0);
}*/
