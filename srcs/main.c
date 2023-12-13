/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:00:57 by tpotilli          #+#    #+#             */
/*   Updated: 2023/12/13 14:09:40 by tpotilli         ###   ########.fr       */
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

	(void)argc;
	if (init_before_pipe(argv, envp) == -1)
		return (-1);
	return (0);
}

int	init_before_pipe(char *argv[], char *envp[])
{
	t_pipes		*pipes;
	int			nb;

	nb = get_nb_pipes(argv);
	fprintf(stderr, "voici le nb %i avant d'inititaliser tout\n", nb);
	pipes = init_pipes(argv, envp);
	if (!pipes)
		return (-1);
	ft_pipex(pipes, nb);
	return (0);
}

// int		cpy_arg(t_pipes *pipes, char *new[])
// {
// 	int	i;
// 	int	j;
// 	int	c;

// 	c = 0;
// 	i = 1;
// 	pipes->argv = malloc(sizeof(char *) * (ft_strlen(new[i])));
// 	if (!pipes->argv)
// 		return (perror("problem with input\n"), -1);
// 	while (new[i])
// 	{
// 		j = 0;
// 		pipes->argv[c] = malloc(sizeof(char) * (ft_strlen_db(new, i) + 1));
// 		if (!pipes->argv[c])
// 			return (perror("problem with input\n"), -1);
// 		while (new[i][j])
// 		{
// 			pipes->argv[c][j] = new[i][j];
// 			j++;
// 		}
// 		pipes->argv[c][j] = '\0';
// 		i++;
// 		c++;
// 	}
// 	pipes->argv[c] = '\0';
// 	return (0);
// }

void	free_db_tab(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
