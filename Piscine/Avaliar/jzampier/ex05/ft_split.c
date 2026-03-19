/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzampier <jzampier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 18:13:43 by jzampier          #+#    #+#             */
/*   Updated: 2026/03/19 16:55:39 by jzampier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_sep(char c, char *charset)
{
	while (*charset)
	{
		if (*charset == c)
			return (1);
		charset++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if ((i == 0 && !is_sep(str[i], charset))
			|| (is_sep(str[i - 1], charset)
				&& !is_sep(str[i], charset) && i > 0))
			count++;
		i++;
	}
	return (count);
}

char	*get_word(char *str, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((end - start) * sizeof(char) + 1);
	while (start < end)
	{
		word[i] = str[start];
		start++;
		i++;
	}
	word[i] = '\0';
	return (word);
}

void	build_split(char *str, char *charset, char **split_strings, int size)
{
	int	split_i;
	int	start;
	int	i;

	i = 0;
	split_i = 0;
	start = -1;
	while (i <= size)
	{
		if (!is_sep(str[i], charset)
			&& ((i > 0 && is_sep(str[i - 1], charset) && str[i]) || (i == 0)))
			start = i;
		if (!str[i] || (is_sep(str[i], charset) && !is_sep(str[i - 1], charset)
				&& i > 0))
		{
			if (start != -1)
			{
				split_strings[split_i] = get_word(str, start, i);
				start = -1;
				split_i++;
			}
		}
		i++;
	}
	split_strings[split_i] = NULL;
}

char	**ft_split(char *str, char *charset)
{
	char	**split_strings;
	int		size;

	split_strings = malloc(((count_words(str, charset) + 1) * sizeof(char *)));
	size = 0;
	while (str[size])
		size++;
	build_split(str, charset, split_strings, size);
	return (split_strings);
}

/* #define MSG_ERROR "%s expected 2 arguments, <string to split> <separator>"
#include <stdio.h>
int	main(int argc, char *argv[])
{
 	if (argc != 3)
	{
		printf(MSG_ERROR, argv[0]);
		return (0);
	}
	int	i = 0;
	char **splited_strings;
	splited_strings = ft_split(argv[1], argv[2]);
	printf("splitted strings: \n");
	while(i < count_words(argv[1], argv[2]))
	{
		printf("%s\n", splited_strings[i]);
		free(splited_strings[i]);
		i++;
	}
	printf("count_words: %d", count_words(argv[1], argv[2]));
	free(splited_strings);
	return (0);
} */