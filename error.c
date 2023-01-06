/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 11:50:48 by hyungjup          #+#    #+#             */
/*   Updated: 2023/01/06 18:37:51 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_perror(char *str)
{
	perror(str);
	exit (1);
}

int	error_message(char *str)
{
	write(2, strerror(errno), ft_strlen(strerror(errno)));
	write(2, " : ", 3);
	write(2, str, ft_strlen(str));
	return (1);
}
