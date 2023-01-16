/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:11:43 by hyungjup          #+#    #+#             */
/*   Updated: 2023/01/16 11:46:01 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child_process(t_pipex pipex, char *av[], char *envp[])
{
	pipex.infile = open(av[1], O_RDONLY);
	if (pipex.infile == -1)
		ft_error("Infile is not exist");
	dup2(pipex.fd[1], STDOUT_FILENO);
	dup2(pipex.infile, STDIN_FILENO);
	close(pipex.fd[0]);
	pipex.cmd_args = ft_split(av[2], ' ');
	pipex.cmd = find_cmd(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		ft_child_free(pipex);
		ft_error("Command not found");
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
}

void	ft_parent_process(t_pipex pipex, char *av[], char *envp[])
{
	pipex.outfile = open (av[4], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (pipex.outfile == -1)
		ft_error("Permission denied");
	dup2(pipex.fd[0], STDIN_FILENO);
	dup2(pipex.outfile, STDOUT_FILENO);
	close(pipex.fd[1]);
	pipex.cmd_args = ft_split(av[3], ' ');
	pipex.cmd = find_cmd(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		ft_child_free(pipex);
		ft_error("Command not found");
	}
	waitpid(pipex.pid, NULL, WNOHANG);
	execve(pipex.cmd, pipex.cmd_args, envp);
}

int	main(int ac, char *av[], char *envp[])
{
	t_pipex	pipex;

	if (ac != 5)
		ft_error("Invalid numbers of arguments");
	if (pipe(pipex.fd) == -1)
		ft_error("Pipe Error");
	pipex.paths = find_path(envp);
	pipex.cmd_paths = ft_split(pipex.paths, ':');
	pipex.pid = fork();
	if (pipex.pid == -1)
		ft_error("Fork Error");
	else if (pipex.pid == 0)
		ft_child_process(pipex, av, envp);
	else
		ft_parent_process(pipex, av, envp);
	ft_parent_free(pipex);
	return (0);
}
