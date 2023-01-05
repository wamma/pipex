/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 11:22:32 by hyungjup          #+#    #+#             */
/*   Updated: 2023/01/05 16:46:13 by hyungjup         ###   ########.fr       */
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
	pid_t	pid1;
	pid_t	pid2;
	int		fd[2];
	int		file_in;
	int		file_out;
	char	*paths;
	char	*cmd;
	char	**cmd_paths;
	char	**cmd_args;

}	t_pipex;

int		error_message(char *str);
int		ft_perror(char *str);
char	*find_paths(char **envp);
char	*find_cmd(char **path, char *cmd);
void	parent_process_free(t_pipex *pipex);
void	child_process_free(t_pipex *pipex);
char	**ft_split(char const *str, char c);
void	fd1(t_pipex pipex, char *av[], char *envp[]);
void	fd2(t_pipex pipex, char *av[], char *envp[]);
void	fd2(t_pipex pipex, char *av[], char *envp[]);
int		main(int ac, char *av[], char *envp[]);
int		ft_strlen(char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char *s1, char *s2);

#endif