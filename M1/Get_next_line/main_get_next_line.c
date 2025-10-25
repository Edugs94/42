/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:20:48 by egalindo          #+#    #+#             */
/*   Updated: 2025/10/25 17:07:09 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

static int	ft_check_args(int argc)
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
	char			*str;
	int			fd;

	if (ft_check_args(argc) < 0)
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		write (1, "Cannot read file.\n", 18);
		return (-1);
	}
	str = get_next_line(fd);
	if (!str)
		return (-1);
	while (str)
	{
		printf("%s", str);
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	close(fd);
}
