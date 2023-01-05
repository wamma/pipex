/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:28:30 by hyungjup          #+#    #+#             */
/*   Updated: 2023/01/05 15:31:36 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent_process_free(t_pipex *pipex)
{
	int	i;

	i = 0;
	close(pipex->file_in);
	close(pipex->file_out);
	while (pipex->cmd_paths[i])
	{
		free(pipex->cmd_paths[i]);
		i++;
	}
	free(pipex->cmd_paths);
}

void	child_process_free(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->cmd_args[i])
	{
		free(pipex->cmd_args[i]);
		i++;
	}
	free(pipex->cmd_args);
	free(pipex->cmd);
}
