/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfurtado <lfurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 17:34:04 by lfurtado          #+#    #+#             */
/*   Updated: 2026/05/20 19:07:28 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_params(int argc, char *argv[])
{
	int		i_argc;
	int		i_argv;

	i_argc = 1;
	while (i_argc < argc)
	{
		i_argv = 0;
		while (argv[i_argc][i_argv] != '\0')
		{
			ft_putchar(argv[i_argc][i_argv]);
			i_argv++;
		}
		ft_putchar('\n');
		i_argc++;
	}
}

int	main(int argc, char *argv[])
{
	ft_print_params(argc, argv);
}
