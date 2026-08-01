/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfurtado <lfurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 18:40:53 by lfurtado          #+#    #+#             */
/*   Updated: 2026/06/11 18:51:08 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*ptr_tmp;

	if (!lst)
		return (0);
	i = 1;
	ptr_tmp = lst;
	while (ptr_tmp->next)
	{
		ptr_tmp = ptr_tmp->next;
		i++;
	}
	return (i);
}
