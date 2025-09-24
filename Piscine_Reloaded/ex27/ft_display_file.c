/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 15:32:26 by egalindo          #+#    #+#             */
/*   Updated: 2025/09/24 16:42:24 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int	ft_check_args(int argc)
{
	if (argc < 2)
	{
		write (1, "File name missing.\n", 19);
		return (-1);
	}
	if (argc > 2)
	{
		write (1, "Too many arguments.\n", 20);
		return (-1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	ssize_t		bytes;
	char		buffer[30000];
	int			fd;

	if (ft_check_args(argc) < 0)
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		write (1, "Cannot read file.\n", 18);
		return (-1);
	}
	bytes = read(fd, buffer, sizeof(buffer));
	while (bytes > 0)
	{
		write(1, buffer, bytes);
		bytes = read(fd, buffer, sizeof(buffer));
	}
	close(fd);
}
