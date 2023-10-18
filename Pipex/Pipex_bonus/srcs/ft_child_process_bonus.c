/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child_process_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:58:51 by tpotilli          #+#    #+#             */
/*   Updated: 2023/10/18 17:20:07 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

void	child_process_bonus(int fd1, t_struct *list, int *end)
{
	close(end[0]);
	/*if (dup2 < 0)
		return ;*/
	dup2(fd1, STDIN_FILENO);
	dup2(end[1], STDOUT_FILENO);
	ft_do_process_bonus(list, list->argv[2]);
	close(end[1]);
	close(fd1);
}
