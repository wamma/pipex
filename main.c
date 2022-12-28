/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:09:50 by hyungjup          #+#    #+#             */
/*   Updated: 2022/12/28 14:47:18 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

int	main(int ac, char **av)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
	{
		fprintf(stderr, "pipe error: %s\n", strerror(errno));
		return (1);
	}
	pid = fork();
	if (pid == 0)
	{
		dup2(fd[1], 1);

		close(fd[0]);
		int ste = execlp("ls", "ls", "-l", NULL);
		if (ste == -1)
		{
			fprintf(stderr, "runerr: %s\n", strerror(errno));
			return (1);
		}
	}
	dup2(fd[0], 0);

	close(fd[1]);
	char line[255];

	while (fgets(line, sizeof(line), stdin) != 0)
		printf("%s", line);
	return (0);
}
