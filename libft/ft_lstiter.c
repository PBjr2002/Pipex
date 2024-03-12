/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:10:57 by pauberna          #+#    #+#             */
/*   Updated: 2024/01/26 12:42:41 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(int))
{
	if (lst == NULL)
		return ;
	while (lst != NULL)
	{
		f(lst->x);
		f(lst->y);
		lst = lst->next;
	}
}

/*void	function(void *content)
{
	printf("%s\n", (char *)content);
}

int	main(void)
{
	t_list	*new;
	t_list	*new1;
	t_list	*new2;
	
	new = ft_lstnew("isto n e suposto ser mexido");
	new1 = ft_lstnew("mas isto e");
	new2 = ft_lstnew("isto tambem");
	ft_lstadd_back(&new, new1);
	ft_lstadd_back(&new1, new2);
	ft_lstiter(new, function);
	return (0);
}*/
