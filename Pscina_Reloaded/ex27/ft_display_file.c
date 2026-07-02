/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfurtado <lfurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 20:09:56 by lfurtado          #+#    #+#             */
/*   Updated: 2026/05/22 20:59:17 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(2, str++, 1);
}

int	main(int argc, char *argv[])
{
	int		fd;
	int		bytes;
	char	c_buf[42];

	fd = -1;
	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	if (fd >= 0)
	{
		bytes = read(fd, c_buf, 42);
		while (bytes > 0)
		{
			write(1, c_buf, bytes);
			bytes = read(fd, c_buf, 42);
		}
		close(fd);
		return (0);
	}
	if (argc == 1)
		ft_putstr("File name missing.\n");
	if (argc > 2)
		ft_putstr("Too many arguments.\n");
	return (1);
}
