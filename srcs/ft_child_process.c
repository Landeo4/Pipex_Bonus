/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:58:51 by tpotilli          #+#    #+#             */
/*   Updated: 2023/11/30 11:30:51 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
**	This function takes as parameter: 
**
**	int fd
**	char *argv[], 
**  char *envp[],
**  int *end
**
** =====================================================
** =====================================================
**
** 
*/

// void	child_process_redirection(t_pipes *pipes)
// {
// 	int	fd;

// 	close(pipes->pipes[0]);
// 	fd = ft_create_fd(pipes[i].fd1, O_RDONLY); // trouver nom fichier argv[4]
// 	if (fd < 0)
// 		return (close(pipes->pipes[1]), exit(errno));
// 	if (dup2(fd, STDIN_FILENO) < 0)
// 		return (close(pipes->pipes[1]), close(fd), perror("dup2"), exit(errno));
// 	close(fd);
// 	if (dup2(pipes->pipes[1], STDOUT_FILENO) < 0)
// 		return (close(pipes->pipes[1]), perror("dup2"), exit(errno));
// 	close(pipes->pipes[1]);
// 	ft_do_process(pipes->env, pipes->argv[2]); // trouver commande (2)
// }

// version pipes

void	child_process_in(t_pipes *pipes)
{
	int	fd;

	close(pipes->pipes[0]);
	printf("pipes[i].fd1 = %s", pipes[0].fd1);
	fd = ft_create_fd(pipes[0].fd1, O_RDONLY); // trouver nom fichier argv[4]
	if (fd < 0)
		return (close(pipes->pipes[1]), exit(errno));
	if (dup2(fd, STDIN_FILENO) < 0)
		return (close(pipes->pipes[1]), close(fd), perror("dup2"), exit(errno));
	close(fd);
	if (dup2(pipes->pipes[1], STDOUT_FILENO) < 0)
		return (close(pipes->pipes[1]), perror("dup2"), exit(errno));
	close(pipes->pipes[1]);
	ft_do_process(pipes->env, pipes->argv[2]); // trouver commande (2)
}

void	child_process_middle(t_pipes *pipes, int i)
{
	int	fd;

	close(pipes->pipes[0]);
	fd = ft_create_fd(pipes[i].fd1, O_RDONLY); // trouver nom fichier argv[4]
	if (fd < 0)
		return (close(pipes->pipes[1]), exit(errno));
	if (dup2(fd, STDIN_FILENO) < 0)
		return (close(pipes->pipes[1]), close(fd), perror("dup2"), exit(errno));
	close(fd);
	if (dup2(pipes->pipes[1], STDOUT_FILENO) < 0)
		return (close(pipes->pipes[1]), perror("dup2"), exit(errno));
	close(pipes->pipes[1]);
	ft_do_process(pipes->env, pipes->argv[2]); // trouver commande (2)
}

void	child_process_out(t_pipes *pipes, int i)
{
	int		fd;

	close (pipes->pipes[1]);
	if (dup2(pipes[i].pipes[0], STDIN_FILENO) < 0)
		return (close(pipes->pipes[0]), perror("dup2"), exit(errno));
	close(pipes[i].pipes[0]);
	printf("pipes[i].fd2 = %s", pipes[i].fd2);
	fd = ft_create_fd(pipes[i].fd2, O_WRONLY | O_CREAT | O_TRUNC); // trouver le fichier argv[4]
	if (fd < 0)
		return (exit(errno));
	if (dup2(fd, STDOUT_FILENO) < 0)
		return (close(pipes->pipes[0]), close(fd), perror("dup2"), exit(errno));
	close (fd);
	printf("argv[--i] = %s", pipes->argv[i - 2]);
	ft_do_process(pipes->env, pipes->argv[--i]); // trouver la commande (3)
}

// void	ft_close(int *fd)
// {
// 	if (*fd >= 3)
// 	{
// 		close(*fd);
// 		*fd = -2;
// 	}
// }

// void	ft_free(void **ptr)
// {
// 	if (*ptr)
// 	{
// 		free(*ptr);
// 		*ptr = NULL;
// 	}
// }