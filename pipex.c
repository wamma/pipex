/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 16:23:54 by hyungjup          #+#    #+#             */
/*   Updated: 2023/01/03 17:52:12 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pid1_execute(int *fd, char *av[], char *envp[])
{
	int	file_in;

	file_in = open(av[1], O_RDONLY);
	if (file_in < 0)
		ft_error("input file error");
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		ft_error("error");
	if (dup2(fd[1], STDIN_FILENO) == -1)
		ft_error("error");
	close(file_in);
	close(fd[0]);
	close(fd[1]);
}

int	main(int ac, char *av[], char *envp[])
{
	int	fd[2];
	int	pid1;
	int	pid2;

	if (ac != 5)
		return (ft_error("Error: wrong count of arguments\n"));
	if (pipe(fd) == -1)
		ft_perror("error");
	pid1 = fork();
	if (pid1 == -1)
		ft_perror("error");
	if (pid1 == 0)
		pid1_execute(fd, av, envp);
}
