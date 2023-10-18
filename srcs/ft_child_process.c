/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:58:51 by tpotilli          #+#    #+#             */
/*   Updated: 2023/10/18 09:33:56 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
**	This function takes as parameter: 
**
**	int fd
**	char *argv[], 
**  char *envp[],
**  int *end
**
** =====================================================
** =====================================================
**
** 
*/

void	child_process(int fd1, char *argv[], char *envp[], int *end)
{
	close(end[0]);
	/*if (dup2 < 0)
		return (1);*/
	dup2(fd1, STDIN_FILENO);
	dup2(end[1], STDOUT_FILENO);
	ft_do_process(envp, argv[2]);
	close(end[1]);
	close(fd1);
}
