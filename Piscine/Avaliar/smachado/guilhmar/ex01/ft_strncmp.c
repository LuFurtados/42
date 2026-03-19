/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfurtado <lfurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 21:29:46 by qlrd              #+#    #+#             */
/*   Updated: 2026/03/16 16:11:08 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *	ft_strncmp
 *
 *	# About
 *
 *  Compare the first (at most) n bytes of `s1` and `s2`
 *
 *  Simulate UNIX `strncmp`.
 *
 * 	# Example
 *
 *	```c
 * 	int	ft_strncmp(char *s1, char *s2, unsigned int n);

 * 	int	main(void)
 *	{
 *		unsigned int	res;
 *
 *		res = ft_strncmp("hello", "hellno", 2);
 *		if (res != 0)
 *			return (res);
 *		return (0);
 *	}
 *	```
 *
 *	@param[*s1]:	`char*`				pointer to string `s1`;
 *	@param[*s2]:	`char*` 			pointer to string `s2`;
 *	@param[n]:		`unsigned int n`	the lenght of substring.
 *  ```
 */
int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	unsigned char	res;

	i = 0;
	if (n == 0)
		return (0);
	else if (n < 1)
	{
		res = *(unsigned char *) s1 - *(unsigned char *) s2;
		return (res);
	}
	else
	{
		while (s1[i] && (s1[i] == s2[i]) && i < n)
		{
			if (*s1 != *s2 || *s1 == '\0')
			{
				return ((*(unsigned char *) s1) - (*(unsigned char *) s2));
			}
			i++ ;
			s1++;
			s2++;
		}
		return (*(unsigned char *) s1 - *(unsigned char *) s2);
	}
}
 #include <stdio.h>
 int	main(void)
 {
 	unsigned int	res;
 
	res = ft_strncmp("hillo", "hellno", 1);
 	printf("%i", res);
 	return (0);
 }