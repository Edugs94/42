/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 08:05:40 by egalindo          #+#    #+#             */
/*   Updated: 2025/11/11 18:18:13 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_handler(int n)
{
	if (n == 1)
	{
		//mejor usar ft_putstr_fd
		ft_printf("Incorrect quantity of arguments, please make sure");
		ft_printf("to introduce:\n");
		ft_printf("./pipex infile cmd1 cmd2 outfile\n");
	}
	exit(0);
}

char	*get_path(char **env)
{
}

int	execute (char *cmd, char **env)
{
	char	**cmd_splitted;
	char	*path;
	
	path = get_path(env);// asi??
	cmd_splitted = ft_split(cmd);
	execve(path, cmd_splitted, env); // si falla por no encontrar archivo o lo que sea escribir error y salir
}

int	main(int argc, char **argv, char **env)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		infile;
	int		outfile;
	char	*cmd1 = argv[2];
	char	*cmd2 = argv[3];

	//arg_checker(argc, argv);
	if (argc != 5)
		exit_handler(1);
	if (pipe(fd) == -1)
		return (-1);
	pid1 =fork();
	if (pid1 < 0) // falla creacion de fork
		exit(-1);
	if (pid1 == 0) //child
	{
		infile = open(argv[1], O_RDONLY);
		if (infile == -1)
			exit(1);
		dup2(infile, 0);
		close(infile);
		dup2(fd[1], 1);
		close(fd[0]);
		close(fd[1]);
		execute(cmd1, env);
	}
	pid2 = fork();
	if (pid2 < 0)
		exit(-1);
	if (pid2 == 0)
	{
		outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0660);//permisos de lectura yescritura  (para users and groups pero no para others)
		if (outfile == -1)
			exit(1);//sala dice que no deberiamos salirnos y deberiamos trabajar sobre un archivo que no podemos abrir, porque aunque no pueda escribir a un archivo quizas escribe a otroa cosa, hay programas que aunque de error al abrir el archivo continuan en ejecucion)
		dup2(outfile, 1);
		close(outfile);
		dup2(fd[0], 0);
		close(fd[1]);
		close(fd[0]);
		execute(cmd2, env);
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
