/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 11:22:32 by hyungjup          #+#    #+#             */
/*   Updated: 2023/01/03 17:46:32 by hyungjup         ###   ########.fr       */
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
	int		fd[2];
	int		ac;
	char	**av;
	char	**envp;
	pid_t	pid;
	int		file_in;
	int		file_out;
	int		offset;
}	t_pipex

int	ft_put_error(char *str);
int	main(int ac, char *av[], char *envp[]);
int	init_pipex(int ac, char **av, char **envp, t_pipex *pipex);

#endif