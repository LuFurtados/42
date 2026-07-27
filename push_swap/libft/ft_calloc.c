/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfurtado <lfurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 16:53:57 by lfurtado          #+#    #+#             */
/*   Updated: 2026/06/15 20:02:37 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			nbytes;
	unsigned char	*ptr;

	if (nmemb == 0 || size == 0)
		nbytes = 1;
	else
	{
		nbytes = nmemb * size;
		if (nbytes / nmemb != size)
			return (NULL);
	}
	ptr = (unsigned char *)malloc(nbytes);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, nbytes);
	return (ptr);
}
