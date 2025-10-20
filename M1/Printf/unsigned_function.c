/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_function.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 08:18:16 by egalindo          #+#    #+#             */
/*   Updated: 2025/10/20 08:18:16 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static char	*ft_utoa()
{
	
}


unsigned int	ft_print_number(unsigned int n)
{
	char	*str;
	unsigned int	str_len;

	str = ft_utoa(n);
	str_len = ft_print_str(str);
	free(str);
	return (str_len);
}