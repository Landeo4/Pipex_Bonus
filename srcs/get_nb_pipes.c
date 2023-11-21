/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nb_pipes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:57:17 by tpotilli          #+#    #+#             */
/*   Updated: 2023/11/14 10:58:56 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		get_nb_pipes(char **argv)
{
	int		i;
	int		j;
	int		nb;

	i = ((nb = 0));
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '|')
				nb++;
			j++;
		}
		i++;
	}
	return (nb);
}
