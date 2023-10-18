/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:00:57 by tpotilli          #+#    #+#             */
/*   Updated: 2023/10/13 17:28:51 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
**	This function takes as parameter: 
**
**  int argc
**	Char *argv
**	char *envp
**
** =====================================================
** =====================================================
**
** we create the fd1 and fd4 in create_fd
** with the flags :
** fd1 = O_RDONLY = read only so we can read but not modify
** fd4 = O_WRONLY = Write Only we can write but not read
** fd4 = O_CREAT = to create file if does not exist
** fd4 = O_TRUNC = To cahnge the file if he exist
*/

// il me faut une fonction pour les actions de l'enfant et un pour les parents
// il me faut check le fork avant
int	main(int argc, char *argv[], char *envp[])
{
	int		fd1;
	int		fd4;

	if (ft_parsing(argc) == 1)
		return (-1);
	fd1 = ft_create_fd(argv[1], O_RDONLY);
	fd4 = ft_create_fd(argv[4], O_WRONLY | O_CREAT | O_TRUNC);
	if (fd1 < 0 || fd4 < 0)
		return (-1);
	ft_pipex(fd1, fd4, argv, envp);
	return (0);
}
