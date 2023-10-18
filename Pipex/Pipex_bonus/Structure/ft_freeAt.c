/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freeAt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:09:21 by tpotilli          #+#    #+#             */
/*   Updated: 2023/10/18 15:26:41 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

t_list_a	*ft_freeata(t_struct *data, int pos)
{
	int			i;
	t_list_a	*prec;
	t_list_a	*cur;

	prec = data->la;
	cur = data->la;
	if (data->la == NULL)
		return (NULL);
	if (pos == 0)
	{
		data->la = data->la->next;
		free(cur);
		return (data->la);
	}
	i = 0;
	while (i < pos)
	{
		i++;
		prec = cur;
		cur = cur->next;
	}
	prec->next = cur->next;
	free(cur);
	return (data->la);
}

t_list_b	*ft_freeatb(t_struct *data, int pos)
{
	int			i;
	t_list_b	*prec;
	t_list_b	*cur;
	t_list_b	*tete;

	prec = data->lb;
	cur = data->lb;
	tete = data->lb;
	if (data->lb == NULL)
		return (NULL);
	if (pos == 0)
	{
		tete = tete->next;
		free(cur);
		return (data->lb);
	}
	i = 0;
	while (i < pos)
	{
		i++;
		prec = cur;
		cur = cur->next;
	}
	prec->next = cur->next;
	free(cur);
	return (data->lb);
}
