/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfurtado <lfurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 16:32:59 by lfurtado          #+#    #+#             */
/*   Updated: 2026/05/22 13:44:29 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *argv[])
{
	int		i_argv;
	int		count;

	i_argv = 1;
	while (argv[i_argv] != 0)
	{
		count = 0;
		while (argv[i_argv][count] != '\0')
		{
			ft_putchar(argv[i_argv][count]);
			count++;
		}
		ft_putchar('\n');
		i_argv++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 != '\0')
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	ft_print_params(int argc, char *argv[])
{
	int		i_argc;
	int		i_argv;
	char	*tmp;

	i_argc = 1;
	while (i_argc < argc)
	{
		i_argv = 0;
		while (i_argv < argc - 1)
		{
			if (ft_strcmp(argv[i_argv], argv[i_argv + 1]) > 0)
			{
				tmp = argv[i_argv];
				argv[i_argv] = argv[i_argv + 1];
				argv[i_argv + 1] = tmp;
			}
			i_argv++;
		}
		i_argc++;
	}
}

int	main(int argc, char *argv[])
{
	ft_print_params(argc, argv);
	ft_putstr(argv);
}
