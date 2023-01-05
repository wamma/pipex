/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 16:23:54 by hyungjup          #+#    #+#             */
/*   Updated: 2023/01/05 17:17:27 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	fd1(t_pipex pipex, char *av[], char *envp[])
{
	dup2(pipex.fd[1], 1);
	close(pipex.fd[0]);
	dup2(pipex.file_in, 0);
	pipex.cmd_args = ft_split(av[2], ' ');
	pipex.cmd = find_cmd(pipex.paths, pipex.cmd_args[0]);
	if (pipex.cmd == 0)
	{
		child_process_free(&pipex);
		error_message("Command not found\n");
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
}

void	fd2(t_pipex pipex, char *av[], char *envp[])
{
	dup2(pipex.fd[0], 0);
	close(pipex.fd[1]);
	dup2(pipex.file_out, 1);
	pipex.cmd_args = ft_split(av[3], ' ');
	pipex.cmd = find_cmd(pipex.paths, pipex.cmd_args[0]);
	if (pipex.cmd == 0)
	{
		parent_process_free(&pipex);
		error_message("Command not found\n");
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
}

void	close_pipes(t_pipex *pipex)
{
	close(pipex->fd[0]);
	close(pipex->fd[1]);
}

int	main(int ac, char *av[], char *envp[])
{
	t_pipex	pipex;

	if (ac != 5)
		return (ft_perror("Error"));
	pipex.file_in = open(av[1], O_RDONLY);
	if (pipex.file_in < 0)
		error_message("Infile Error");
	pipex.file_out = open(av[ac - 1], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (pipex.file_out < 0)
		error_message("Outfile Error");
	if (pipe(pipex.fd) < 0)
		error_message("Pipe Error");
	pipex.paths = find_paths(envp);
	pipex.cmd_paths = ft_split(pipex.paths, ':');
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
		fd1(pipex, av, envp);
	pipex.pid2 = fork();
	if (pipex.pid2 == 0)
		fd2(pipex, av, envp);
	close_pipes(&pipex);
}
