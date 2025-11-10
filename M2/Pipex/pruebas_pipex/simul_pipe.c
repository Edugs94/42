/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simul_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 09:28:56 by egalindo          #+#    #+#             */
/*   Updated: 2025/11/10 15:32:06 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int	main (int argc, char **argv, char **env)
{
	int		fd[2];
	char	*cmd1;
	char	*cmd2;
	int		pid1;
	int		pid2;

	if(pipe(fd) == -1)
		return (-1);
	pid1 = fork();
	if (pid1 < 0)
		return (3);
	if (pid1 == 0)
	{
	// Child process 1 (ping)
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		//execlp ("ping", "ping", "-c", "5","google.com", NULL);
		//execve (comando_path, argumentos_array, env);
		execve ("usr/bin/ls", argumentos_array, env);
	}
	pid2 = fork();
	if (pid2 < 0)
		return 3;
	if (pid2 == 0)
	{
	//Child process 2 (grep)
		dup2(fd[0], STDIN_FILENO);
		close (fd[0]);
		close (fd[1]);
		execlp ("grep", "grep", "rtt",NULL);
	}
	close (fd[0]);
	close (fd[1]);

	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
