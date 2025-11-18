/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 10:57:22 by egalindo          #+#    #+#             */
/*   Updated: 2025/11/08 14:34:34 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// si infile, argv[1] no existe -> imprime: zsh: no such file or directory: <argv[1]> y lo trata como un fichero vacio (si haces cat | cat deja el output vacio, si hace count cuenta 0 bytes)
// si outfile argv[4] no existe entonces lo crea y lo rellena
int	arg_check(int argc, char **argv)
{
	if (argc != 5)
		return (-1);
	else
		//revisar tambien que argv2 y argv3 sean comandos
		return (0);
}
