/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 16:23:54 by hyungjup          #+#    #+#             */
/*   Updated: 2023/01/06 18:39:54 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_cmd(char **path, char *cmd)
{
	char	*tmp;
	char	*path_name;

	while (*path)
	{
		tmp = ft_strjoin(*path, "/");
		path_name = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(path_name, X_OK) != -1)
			return (path_name);
		free(path_name);
		path++;
	}
	return (NULL);
}

void	child_process(t_pipex pipex, char *av[], char *envp[])
{
	pipex.file_in = open(av[1], O_RDONLY);
	if (pipex.file_in == -1)
		error_message("infile error");
	dup2(pipex.fd[1], 1);
	close(pipex.fd[0]);
	dup2(pipex.file_in, 0);
	pipex.cmd_args = ft_split(av[2], ' ');
	pipex.cmd = find_cmd(pipex.cmd_paths, pipex.cmd_args[0]);
	if (pipex.cmd == 0)
	{
		child_process_free(&pipex);
		error_message("Command not found\n");
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
}

void	parent_process(t_pipex pipex, char *av[], char *envp[])
{
	dup2(pipex.fd[0], 0);
	close(pipex.fd[1]);
	dup2(pipex.file_out, 1);
	pipex.cmd_args = ft_split(av[3], ' ');
	pipex.cmd = find_cmd(pipex.cmd_paths, pipex.cmd_args[0]);
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
		return (ft_perror("Argument Error"));
	pipex.paths = find_paths(envp);
	pipex.cmd_paths = ft_split(pipex.paths, ':');
	pipex.pid = fork();
	if (pipex.pid == 0)
		child_process(pipex, av, envp);
	else
		parent_process(pipex, av, envp);
	close_pipes(&pipex);
	waitpid(pipex.pid, NULL, 0);
	parent_process_free(&pipex);
	return (0);
}
