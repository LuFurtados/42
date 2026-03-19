/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhmar <qlrd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 00:00:00 by guilhmar          #+#    #+#             */
/*   Updated: 2026/03/15 00:00:00 by guilhmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *	ft_strstr
 *
 *	#	About
 *
 *	Locate the first occurrence of the null-terminated string (`'\0'` or
 *	`0x00`) in `to_find` in the null-terminated string `str`.
 *
 *	If `to_find` is an empty string, `str` is returned. If to_find occurs
 *	nowhere in `str`, `NULL` is returned. Otherwise a pointer to the first
 *	character of the first occurrence of to_find is returned.
 *
 *	# Example
 *
 *  ```c
 *	int	main (void)
 *	{
 *		char	*result;
 *
 *		result = ft_strstr("hello, world!", "world");
 *		if (result != "world!")
 *			return (1);
 *		return (0);
 *	}
 *  ```
 *
 *	@param[str]:		`char *`	pointer to the string to search in;
 *	@param[to_find]:	`char *`	pointer to the substring to find;
 *	@return[char*]
 */
char	*ft_strstr(char *str, char *to_find)
{
	char	*tf;
	char	*ts;

	if (!*to_find)
		return (str);
	ts = str;
	tf = to_find;
	while (*ts)
	{
		str = ts;
		to_find = tf;
		while (*to_find && *str == *to_find)
		{
			str++;
			to_find++;
		}
		if (!*to_find)
			return (ts);
		ts++;
	}
	return (0);
}
