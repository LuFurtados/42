/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhmar <qlrd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 00:00:00 by guilhmar          #+#    #+#             */
/*   Updated: 2026/03/15 00:00:00 by guilhmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	len ;

	len = 0;
	while (*str)
	{
		len++ ;
		str++ ;
	}
	return (len);
}

/*
 *	ft_strncat
 *
 *	#	About
 *
 *	Append at most nb bytes from the src string to the dest string,
 * 	overwriting the terminating null byte ('\0') at the end of dest,
 * 	and then adds a terminating null byte.
 *
 *	The strings may not overlap, and the dest string must have enough space
 *	for the result. If dest is not large enough, program behavior is
 *	unpredictable; **buffer overruns are a favorite avenue for attacking
 *	secure programs**.
 *
 *	# Example
 *
 *  ```c
 *	int	main (void)
 *	{
 *		char	dest[20] = "hello, ";
 *
 *		ft_strncat(dest, "world!!!", 5);
 *		if (dest != "hello, world")
 *			return (1);
 *		return (0);
 *	}
 *  ```
 *
 *	@param[dest]:	`char *`		pointer to `dest` string;
 *	@param[src]:	`char *`		pointer to `src` string;
 *	@param[nb]:		`unsigned int`	max amount of bytes to append;
 *	@return[char*]
 */
char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	len;
	char			*ret;

	ret = dest;
	i = 0;
	len = (unsigned int)ft_strlen(dest);
	while (i < len)
	{
		dest++;
		i++;
	}
	i = 0;
	while (*src && i < nb)
	{
		*dest = *src;
		dest++;
		src++;
		i++;
	}
	*dest = '\0';
	return (ret);
}
