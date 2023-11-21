/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:41:43 by tpotilli          #+#    #+#             */
/*   Updated: 2023/11/21 14:45:06 by tpotilli         ###   ########.fr       */
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

int	ft_pipex(char *argv[], char *envp[])
{
	pid_t		pid[2];
	t_pipes		*fd_pipes;
	int			i;
	int			nb_pipes;

	printf("au debut de pipex\n");
	fd_pipex->cpt_intput = 0;
	fd_pipex->cot_output = 0;
	nb_pipes = get_nb_pipes(argv);
	fd_pipes = malloc(sizeof(t_pipes) * nb_pipes);
	i = 0;
	printf("juste avant les pipes\n");
	while (i < nb_pipes)
	{
		if (pipe(fd_pipes->pipes) < 0)
			return (perror("pipes"), 1);
		i++;
	}
	i = 0;
	printf("je passe par la\n");
	while (i < nb_pipes)
	{
		pid[i] = fork();
		if (pid[i] < 0)
			return (1);
		if (pid[i] == 0)
		{
			if (i > 0)
				child_process_start(argv, envp, fd_pipes->pipes);
			else
				child_process_end(argv, envp, fd_pipes->pipes);
		}
		i++;
	}
	printf("fin du code\n");
	close_all_pipe(fd_pipes, nb_pipes);
	close_all_pid(nb_pipes, pid);
	return (0);
}

void	close_all_pid(int nb_pipes, pid_t *pid)
{
	int			i;
	int			status;

	i = 0;
	while (i < nb_pipes)
	{
		waitpid(pid[0], &status, 0);
		waitpid(pid[1], &status, 0);
		i++;
	}
	
}

void	close_all_pipe(t_pipes *fd_pipes, int nb_pipes)
{
	while (nb_pipes > 0)
	{
		close(fd_pipes->pipes[0]);
		close(fd_pipes->pipes[1]);
		nb_pipes--;
	}
}

//end[1] == child process ->write
//end[0] == parent process ->read
//cm1 will be executed by child and cm2 by parent