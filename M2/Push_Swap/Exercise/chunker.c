/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 17:01:32 by egalindo          #+#    #+#             */
/*   Updated: 2025/11/15 17:22:38 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	ft_sqrt(int n)
{
	int i;

	i = 0;
	while((i * i) < n)
		i++;
	if ((i * i) > n)
		return (i - 1);
	else
		return (i);
}

int	chunk_calculator(int size)
{
	return((3/4) * ft_sqrt(size))
}


