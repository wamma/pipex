/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:47:56 by hyungjup          #+#    #+#             */
/*   Updated: 2023/01/16 11:46:54 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child_free(t_pipex pipex)
{
	int	i;

	i = 0;
	while (pipex.cmd_args[i])
	{
		free(pipex.cmd_args[i]);
		i++;
	}
	free(pipex.cmd_args);
	free(pipex.cmd);
}

void	ft_parent_free(t_pipex pipex)
{
	int	i;

	i = 0;
	close(pipex.infile);
	close(pipex.outfile);
	while (pipex.cmd_paths[i])
	{
		free(pipex.cmd_paths[i]);
		i++;
	}
	free(pipex.cmd_paths);
}
