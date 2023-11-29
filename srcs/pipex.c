/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 09:28:48 by tpotilli          #+#    #+#             */
/*   Updated: 2023/11/29 10:31:45 by tpotilli         ###   ########.fr       */
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

// int	ft_pipex(t_pipes *pipes)
// {
// 	pid_t	pid[2];
// 	// int		end[get_nb_pipes(argv)];
// 	int		status;
// 	int		i;
// 	int		nb;

// 	nb = get_nb_pipes(argv);
// 	pipes = malloc(sizeof(pipes) * nb);
// 	if (!pipes)
//     	return (-1);
// 	i = 0;
// 	while (i < nb)
// 	{
// 		if (pipe(pipes[i].pipes) == -1)
// 		{
// 			free(pipes);
// 			return (-1);
// 		}
// 		i++;
// 	}
// 	i = 0;
// 	while (i < nb)
// 	{
// 		pid[i] = fork();
// 		if (pid[i] < 0)
// 			return (1);
// 		if (pid[i] == 0)
// 		{
// 			if (i == 0)
// 				child_process_start(pipes, );
// 			else
// 				child_process_end(pipes, );
// 		}
// 		i++;
// 	}
// 	return (close(pipes->pipes[0]), close(pipes->pipes[1]), waitpid(pid[1], &status, 0)
// 		, waitpid(pid[0], &status, 0), 0);
// }

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

//end[1] == child process ->write
//end[0] == parent process ->read
//cm1 will be executed by child and cm2 by parent