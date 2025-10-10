/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 09:30:00 by egalindo          #+#    #+#             */
/*   Updated: 2025/09/24 12:09:12 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		str++;
		len++;
	}
	return (len);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(src);
	dest = (char *)malloc(sizeof(char) * len + 1);
	if (dest == NULL)
		return (NULL);
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[len] = '\0';
	return (dest);
}
/*
int	main(int argc, char **argv)
{
	char	*str;

	if(argc < 2)
		return (-1);
	str = ft_strdup(argv[1]);
	printf("%s",str);
	free (str);
	return (0);
}
*/
