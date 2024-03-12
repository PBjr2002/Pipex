/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:15:58 by pauberna          #+#    #+#             */
/*   Updated: 2024/01/30 12:10:56 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
	new->prev = last;
}

/*int	main(void)
{
	t_list	*new;
	t_list	*new1;

	new = ft_lstnew("n sei");
	new1 = ft_lstnew("qual e primeiro");
	ft_lstadd_back(&new, new1);
	printf("%s\n", (char *)new->content);
	printf("%s\n", (char *)new->next->content);
	return (0);
}*/
