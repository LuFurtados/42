/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfurtado <lfurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 16:53:57 by lfurtado          #+#    #+#             */
/*   Updated: 2026/06/02 18:42:46 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			i;
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
	i = 0;
	while (i < nbytes)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
