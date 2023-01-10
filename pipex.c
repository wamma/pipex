/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:40:56 by hyungjup          #+#    #+#             */
/*   Updated: 2023/01/10 16:36:56 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child_process(t_pipex pipex, char **av, char **envp)
{
	dup2(pipex.fd[1], 1);
	close(pipex.fd[0]);
	dup2(pipex.infile, 0);
	pipex.cmd_args = ft_split(av[2], ' ');
	pipex.cmd = find_cmd(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		ft_child_free(pipex);
		error_msg("Command not found");
		exit(1);
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
}

void	ft_parent_process(t_pipex pipex, char **av, char **envp)
{
	dup2(pipex.fd[0], 0);
	close(pipex.fd[1]);
	dup2(pipex.outfile, 1);
	pipex.cmd_args = ft_split(av[3], ' ');
	pipex.cmd = find_cmd(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		ft_parent_free(pipex);
		error_msg("Command not found");
		exit(1);
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	pipex;

	if (ac != 5)
		ft_perror("Invalid numbers of arguments");
	pipex.infile = open(av[1], O_RDONLY);
	if (pipex.infile < 0)
		error_msg("Open Error");
	pipex.outfile = open(av[ac - 1], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (pipex.outfile < 0)
		error_msg("Outfile Error");
	if (pipe(pipex.fd) < 0)
		error_msg("Pipe Error");
	pipex.paths = find_path(envp);
	pipex.cmd_paths = ft_split(pipex.paths, ':');
	pipex.pid = fork();
	if (pipex.pid == -1)
		error_msg("Fork Error");
	else if (pipex.pid == 0)
		ft_child_process(pipex, av, envp);
	else
		ft_parent_process(pipex, av, envp);
	waitpid(pipex.pid, NULL, 0);
	ft_parent_free(pipex);
	return (0);
}
