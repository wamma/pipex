/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:26:21 by hyungjup          #+#    #+#             */
/*   Updated: 2023/01/05 17:16:16 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_paths(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

char	*find_cmd(char **path, char *cmd)
{
	char	*tmp;
	char	*path_name;

	while (*path)
	{
		tmp = ft_strjoin(*path, '/');
		path_name = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(path_name, 0) == 0)
			return (path_name);
		free(path_name);
		path++;
	}
	return (0);
}
