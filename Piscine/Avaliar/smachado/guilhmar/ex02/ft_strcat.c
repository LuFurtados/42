/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfurtado <lfurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 23:22:37 by guilhmar          #+#    #+#             */
/*   Updated: 2026/03/16 16:13:34 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *	ft_strcat
 *
 *	#	About
 *
 *	Append the src string to the dest string, overwriting the terminating null
 * 	byte ('\0') at the end of dest, and then adds a terminating null byte.
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
 *		char *str;
 *
 *		str = ft_strcat("world!", "hello, ", 6);
 *		if (str != "hello, world!")
 *			return (1);
 *		return (0);
 *	}
 *  ```
 *
 *	@param[dest]:	`char *`		pointer to `dest` string;
 *	@param[src]:	`char *`		pointer to `src` string;
 *	@param[n]:		`unsigned int`	amout to be copied;
 *	@return[char*]
 */
char	*ft_strcat(char *dest, char *src)
{
	char	*ret;

	ret = dest;
	while (*dest)
		dest++;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (ret);
}
