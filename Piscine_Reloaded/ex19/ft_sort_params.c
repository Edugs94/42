/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:52:36 by egalindo          #+#    #+#             */
/*   Updated: 2025/09/23 18:52:36 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] == s2[i]) && ((s1[i] || s2[i])))
		i++;
	return (s1[i] - s2[i]);
}

void	ft_sort_args(char **argv, int argc)
{
	int		i;
	int		j;
	char	*aux;

	j = 0;
	while (j < argc)
	{
		i = 2;
		while (argv[i])
		{
			if (ft_strcmp(argv[i - 1], argv[i]) > 0)
			{
				aux = argv[i];
				argv[i] = argv[i - 1];
				argv[i - 1] = aux;
			}
			i++;
		}
		j++;
	}
}

void	ft_print_args(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
			ft_putchar(argv[i][j++]);
		write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (-1);
	ft_sort_args(argv, argc);
	ft_print_args(argv);
	return (0);
}
