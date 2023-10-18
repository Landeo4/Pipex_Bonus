/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_cell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 18:23:00 by tpotilli          #+#    #+#             */
/*   Updated: 2023/10/18 17:33:33 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

t_struct	*ft_createcell(char **argv, char **env, int argc)
{
	t_struct	*cell;

	cell = malloc(sizeof(t_struct));
	if (!cell)
		return (NULL);
	cell->argv = argv;
	cell->env = env;
	cell->argc = argc;
	cell->next = NULL;
	return (cell);
}
