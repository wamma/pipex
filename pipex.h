/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:14:13 by hyungjup          #+#    #+#             */
/*   Updated: 2023/01/16 11:42:33 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_pipex
{
	pid_t	pid;
	int		fd[2];
	int		infile;
	int		outfile;
	char	*paths;
	char	*cmd;
	char	**cmd_paths;
	char	**cmd_args;
}	t_pipex;
/*error.c*/
int		ft_error(char *err);
/*find.c*/
char	*find_cmd(char **path, char *cmd);
char	*find_path(char *envp[]);
/*free.c*/
void	ft_child_free(t_pipex pipex);
void	ft_parent_free(t_pipex pipex);

#endif