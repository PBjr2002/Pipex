/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_last.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:55:53 by pauberna          #+#    #+#             */
/*   Updated: 2024/01/31 12:03:01 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_del_last(t_list *pos)
{
	t_list	*tmp;
	t_list	*before_last;

	tmp = pos;
	while (tmp->next)
	{
		before_last = tmp;
		tmp = tmp->next;
	}
	free(tmp);
	before_last->next = NULL;
}
