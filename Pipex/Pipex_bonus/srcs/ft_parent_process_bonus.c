/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parent_process_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:59:09 by tpotilli          #+#    #+#             */
/*   Updated: 2023/10/18 17:20:43 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	parent_process_bonus(int fd4, t_struct *list, int *end)
{
	close(end[1]);
	dup2(fd4, STDOUT_FILENO);
	dup2(end[0], STDIN_FILENO);
	ft_do_process_bonus(list, list->argv[3]);
	close(end[0]);
	close(fd4);
}
