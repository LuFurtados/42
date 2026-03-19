/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_ft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 23:16:06 by carocha-          #+#    #+#             */
/*   Updated: 2026/03/03 12:07:45 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	ft_ultimate_ft(int *********nbr);

void	ft_ultimate_ft(int *********nbr)
{
	if (nbr && *nbr && **nbr && ***nbr && ****nbr && *****nbr \
		&& ******nbr && *******nbr && ********nbr \
		&& *********nbr)
	{
		*********nbr = 42;
	}
}

int     main(void)
{
        int     n = 30;
	int	*a = &n;
	int	**aa = &a;
	int	***aaa = &aa;
	int	****aaaa = &aaa;
	int	*****aaaaa = &aaaa;
	int	******aaaaaa = &aaaaa;
	int	*******aaaaaaa = &aaaaaa;
	int	********aaaaaaaa = &aaaaaaa;
	int	*********aaaaaaaaa = &aaaaaaaa;
	
	ft_ultimate_ft(aaaaaaaaa);
        printf("%i", n);
        return (0);
}
