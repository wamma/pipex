/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:47:04 by hyungjup          #+#    #+#             */
/*   Updated: 2023/01/10 13:49:16 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_perror(char *err)
{
	perror(err);
	exit (1);
}

int	error_msg(char *err)
{
	write(2, err, ft_strlen(err));
	return (1);
}
