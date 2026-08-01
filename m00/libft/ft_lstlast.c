/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfurtado <lfurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 17:15:45 by lfurtado          #+#    #+#             */
/*   Updated: 2026/06/12 17:22:46 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*ptr_tmp;

	if (!lst)
		return (NULL);
	ptr_tmp = lst;
	while (ptr_tmp->next)
		ptr_tmp = ptr_tmp->next;
	return (ptr_tmp);
}
