/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:05:57 by hyungjup          #+#    #+#             */
/*   Updated: 2023/01/10 15:27:01 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

char	*find_cmd(char **path, char *cmd)
{
	char	*tmp;
	char	*new_cmd;

	while (*path)
	{
		tmp = ft_strjoin(*path, "/");
		new_cmd = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(new_cmd, 0) == 0)
			return (new_cmd);
		free(new_cmd);
		path++;
	}
	return (NULL);
}
