/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:41:48 by hyungjup          #+#    #+#             */
/*   Updated: 2023/01/10 16:44:08 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include <errno.h>
# include <stdlib.h>
# include <string.h>

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
/*pipex.c*/
int		main(int ac, char **av, char **envp);
void	ft_child_proceses(t_pipex pipex, char **av, char **envp);
void	ft_parent_process(t_pipex pipex, char **av, char **envp);
/*utils.c*/
int		ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char *s1, char *s2);
/*error.c*/
void	ft_perror(char *err);
int		error_msg(char *err);
/*find.c*/
char	*find_path(char **envp);
char	*find_cmd(char **path, char *cmd);
/*ft_split.c*/
char	**ft_split(char const *str, char c);
/*free.c*/
void	ft_child_free(t_pipex pipex);
void	ft_parent_free(t_pipex pipex);

#endif