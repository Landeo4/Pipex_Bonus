/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 09:28:48 by tpotilli          #+#    #+#             */
/*   Updated: 2023/12/13 18:17:31 by tpotilli         ###   ########.fr       */
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

int	ft_pipex(t_pipes *pipes, int nb)
{
	pid_t	pid[2];
	// int		end[get_nb_pipes(argv)];
	int		status;
	int		i;

	i = 0;
	if (!pipes)
		return (-1);
	while (i < nb)
	{
		pid[i] = fork();
		if (pid[i] < 0)	
			return (1);
		if (pid[i] == 0)
		{
			if (i == 0)
			{
				printf("======DEBUT DE MON PIPEX======\n");
				child_process_in(pipes);
			}
			else if (i == nb - 1)
			{
				printf("fin\n");
				child_process_out(pipes, i);
				exit(0);
			}
			else
			{
				printf("je passe par middle\n");
				child_process_middle(pipes, i);
			}
		}
		i++;
	}
	i = 0;
	// return (close(pipes->pipes[0]), close(pipes->pipes[1]), free(pipes), 0);
	while (i < nb)
	{
		int pid_result = waitpid(pid[i], &status, 0);
		printf("Attente du processus fils %d, reçu le PID %d\n", pid[i], pid_result);
		i++;
	}
	free(pipes);
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

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

int		get_nb_pipes(char **argv)
{
	int		i;
	int		cpt;
	int		tmp;

	i = ((cpt = 0));
	tmp = 0;
	while (ft_strncmp(argv[i], "./Pipex", 8) != 0)
		i++;
	i = i + 2;
	while (i < found_max(argv))
	{
		tmp++;
		i++;
	}
	cpt = tmp - 2;
	fprintf(stderr, "le nombre de pipe est de %d\n", cpt);
	return (cpt);
}

t_pipes *init_pipes(char *argv[], char *env[])
{
    int			i;
    int			nb;
	t_pipes		*pipes;

    i = 0;
    nb = get_nb_pipes(argv);
    fprintf(stderr, "nb %i\n", nb);
    pipes = malloc(sizeof(t_pipes) * nb);
    if (!pipes)
        return (fprintf(stderr, "malloc problem helloooo\n"), NULL);
    pipes[i].fd1 = argv[1];
	if (!pipes[i].fd1)
    	return (printf("fd1 problem\n"), free(pipes), NULL);
	while (i < nb)
    {
        pipes[i].argv = argv;
        pipes[i].env = env;
        if (!pipes[i].argv || !pipes[i].env)
            return (printf("argv or env problem\n"), free(pipes), NULL);

        if (pipe(pipes[i].pipes) == -1)
            return (printf("pipe problem\n"), free(pipes), NULL);
		i++;
    }
	pipes[i - 1].fd2 = argv[found_max(argv) - 1];
	printf("len %i\n", ft_strlen(pipes[i - 1].fd2));
	if (!pipes[i - 1].fd2)
		return (printf("fd2 problem\n"), free(pipes), NULL);
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