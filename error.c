/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 11:50:48 by hyungjup          #+#    #+#             */
/*   Updated: 2023/01/05 11:33:29 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	error_message(char *str)
{
	write(2, str, ft_strlen(str));
	exit (1);
}

int	ft_perror(char *str)
{
	perror(str);
	return (1);
}
