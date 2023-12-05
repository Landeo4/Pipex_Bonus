/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 09:28:48 by tpotilli          #+#    #+#             */
/*   Updated: 2023/12/05 18:33:41 by tpotilli         ###   ########.fr       */
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

	nb = get_nb_pipes(argv);
	pipes = NULL;
	pipes = init_pipes(pipes, argv, env);
	if (!pipes)
		return (-1);
	i = 0;
	printf("nb %i\n", nb);
	while (i < nb)
	{
		if (pipe(pipes[i].pipes) == -1)
			return (free(pipes), -1);
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
			printf("===\ndans mon pid = 0 i = %d nb = %d\n===\n", i, nb);
			if (i == 0)
			{
				printf("debut de mon PIPex\n");
				child_process_in(pipes);
			}
			else if (i == nb)
			{
				printf("fin\n");
				child_process_out(pipes, i);
			}
			else
			{
				printf("je passe par middle\n");
				child_process_middle(pipes, i);
			}
			exit(0);
		}
		i++;
	}
	i = 0;
	free(pipes);
	// return (close(pipes->pipes[0]), close(pipes->pipes[1]), free(pipes), 0);
	while (i < nb)
	{
		int pid_result = waitpid(pid[i], &status, 0);
		printf("Attente du processus fils %d, reçu le PID %d\n", pid[i], pid_result);
		i++;
	}
	return (0);
}

// while (i < nb)
	// {
	// 	pid[i] = fork();
	// 	if (pid[i] < 0)
	// 		return (1);
	// 	// token = command_type(pipes, i);
	// 	if (pid[i] == 0)
	// 	{
	// 		if (i == 0)
	// 			child_process_in(pipes);
	// 		else if (i == nb--)
	// 			child_process_out(pipes, i);
	// 		else
	// 			child_process_middle(pipes, i);
	// 	}
	// 	i++;
	// }

// int	command_type(t_pipes *pipes, int i)
// {
// 	(void)pipes;
// 	(void)i;
// 	return (1);
// }

// int	is_pipe(t_prompt *prompt)
// {
// 	int	i;

// 	i = -1;
// 	while (prompt->input[++i])
// 		if (prompt->input[i] == '|')
// 			return (1);
// 	return (0);
// }

// faire boucle pour waitpid
// potentiellement integrer mon pipe a ma boucle pid

int	found_max(char **argv)
{
	int	i;

	while (argv[i])
		i++;
	return (i);
}

int		get_nb_pipes(char **argv)
{
	int		i;
	int		cpt;
	int		c;

	i = ((cpt = 0));
	c = 0;
	while (ft_strncmp(argv[i], "./Pipex", 8) != 0)
		i++;
	printf("i = %d\n", i);
	while (i < found_max(argv))
	{
		printf("dans le while i = %d\n", i);
		printf("la string\n argv[i] = %s\n", argv[i]);
		if (argv[i][c] == 34)
		{
			printf("coucou\n");
			while (argv[i])
			{
				i++;
				cpt++;
			}
		}
		i++;
	}
	printf("i = %d\n", i);
	printf("j = %d\n", cpt);
	return (cpt);
}

t_pipes *init_pipes(t_pipes *pipes, char *argv[], char *env[])
{
	int		i;
	int		nb;

	i = 0;
	nb = get_nb_pipes(argv);
	printf("nb %i\n", nb);
	pipes = malloc(sizeof(t_pipes) * nb);
	if (!pipes)
    	return (printf("malloc problem\n"), NULL);
	pipes->fd1 = argv[1];
	if (!pipes->fd1)
		return (printf("fd1 problem\n"), NULL);
	while (argv[i])
		i++;
	pipes->fd2 = argv[--i];
	if (!pipes->fd2)
		return (printf("fd2 problem\n"), NULL);
	pipes->argv = argv;
	pipes->env = env;
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

// gere les redirections