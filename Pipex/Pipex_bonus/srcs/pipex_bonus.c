/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 09:28:48 by tpotilli          #+#    #+#             */
/*   Updated: 2023/10/18 17:16:32 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

int	ft_pipex_bonus(int fd1, int fd2, t_struct *list)
{
	pid_t	pid;
	int		end[2];
	int		status;
	int		i;

	i = count_len_db_bonus(list->argv) - 1;
	while (i > 0)
	{
		pipe(end);
		pid = fork();
		if (pid < 0)
			return (1);
		else if (pid == 0)
			child_process_bonus(fd1, list, end);
		else
			parent_process_bonus(fd2, list, end);
		i--;
	}
	close(end[0]);
	close(end[1]);
	waitpid(pid, &status, 0);
	//faire waitpid pour parent aussi
	//free_all_struct();
	return (0);
}

//end[1] == child process ->write
//end[0] == parent process ->read
//cm1 will be executed by child and cm2 by parent