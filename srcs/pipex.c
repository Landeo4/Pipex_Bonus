/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 09:28:48 by tpotilli          #+#    #+#             */
/*   Updated: 2023/11/29 14:17:18 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
**	This function takes as parameter: 
**
**	Char *argv
**	char *envp
**  int fd1
**  int fd4
**
** =====================================================
** =====================================================
**
** pid_t to stock the identifiers of process
** pipefd[2] tab to stock the identifiers of pid(reading or writing)
** status to verify the status at child
**
** pid1 = fork () call fork to creat a copy of the parent
** if fork work
** -> parent get the child identifiers in pid1
** if doesn't work -> return (1) 
**
** if pid is negative return 1, if pid1 == 0 child process
**
** waitpid() wait the end of parent to wait child
*/

int	ft_pipex(char *argv[], char *env[])
{
	pid_t	pid[2];
	// int		end[get_nb_pipes(argv)];
	int		status;
	int		i;
	int		nb;
	t_pipes	*pipes;

	i = 0;
	nb = get_nb_pipes(argv);
	pipes = NULL;
	pipes = init_pipes(pipes, argv, env);
	if (!pipes)
		return (-1);
	printf("je continue normalement\n");
	while (i < nb)
	{
		if (pipe(pipes[i].pipes) == -1)
		{
			free(pipes);
			return (-1);
		}
		i++;
	}
	i = 0;
	while (i < nb)
	{
		pid[i] = fork();
		if (pid[i] < 0)
			return (1);
		if (pid[i] == 0)
		{
			if (i == 0)
				child_process_start(pipes, i);
			else
				child_process_end(pipes, i);
		}
		i++;
	}
	// return (close(pipes->pipes[0]), close(pipes->pipes[1]), free(pipes), 0);
	while (i > 0)
	{
		waitpid(pid[i], &status, 0);
		i--;
	}
	return (close(pipes->pipes[0]), close(pipes->pipes[1]), free(pipes), 0);
}
// faire boucle pour waitpid
// potentiellement integrer mon pipe a ma boucle pid
int		get_nb_pipes(char **argv)
{
	int		i;
	int		nb;

	i = 0;
	while (argv[i])
		i++;
	nb = i / 2;
	nb--;
	return (nb);
}

t_pipes *init_pipes(t_pipes *pipes, char *argv[], char *env[])
{
	int		i;
	int		nb;

	i = 0;
	nb = get_nb_pipes(argv);
	pipes = malloc(sizeof(t_pipes) * nb);
	if (!pipes)
    	return (printf("malloc problem\n"), NULL);
	pipes->fd1 = argv[1];
	while (argv[i])
		i++;
	pipes->fd2 = argv[--i];
	pipes->argv = argv;
	pipes->env = env;
	// show_db_tab(argv);
	// show_db_tab(env);
	if (!pipes->argv)
		return (printf("argv problem\n"), NULL);
	if (!pipes->env)
		return (printf("env problem\n"), NULL);
	printf("donc maintenant tout va bien\n");
	return (pipes);
}

void	show_db_tab(char **map)
{
	int	i;
	int	j;

	i = 0;
	printf("la map\n");
	if (!map)
		return ;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			printf("%c", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	return ;
}

//end[1] == child process ->write
//end[0] == parent process ->read
//cm1 will be executed by child and cm2 by parent