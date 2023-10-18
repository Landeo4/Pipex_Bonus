/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:53:32 by tpotilli          #+#    #+#             */
/*   Updated: 2023/10/18 17:10:00 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free_all_struct(t_struct *list)
{
	ft_free_argv(list);
	free_env(list);
}

void	ft_free_list(t_struct *list2)
{
	t_struct *list;

	list = list2;
	while (list->argv)
	{
		list = list2->argv->next;
		free(list2->argv);
		list2->argv = list->argv;
	}
	free(list->argv);
}

void free_env(t_struct *list)
{

}
