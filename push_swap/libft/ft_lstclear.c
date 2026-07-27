/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfurtado <lfurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 17:39:45 by lfurtado          #+#    #+#             */
/*   Updated: 2026/06/12 20:57:51 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ptr_tmp;

	if (!lst || !*lst || !del)
		return ;
	while (*lst)
	{
		ptr_tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = ptr_tmp;
	}
	*lst = NULL;
}
