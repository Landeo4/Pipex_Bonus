/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:47:05 by tpotilli          #+#    #+#             */
/*   Updated: 2023/10/18 15:26:48 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_print_lista(t_struct *data)
{
	t_list_a	*tmp;

	tmp = data->la->next;
	if (!tmp)
		return (-1);
	while (tmp)
	{
		ft_printf("%d\n", tmp->num);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_print_listb(t_struct *data)
{
	t_list_b	*tmp;

	tmp = data->lb->next;
	if (!tmp)
		return (-1);
	while (tmp)
	{
		ft_printf("%d\n", tmp->num);
		tmp = tmp->next;
	}
	return (1);
}
