/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:58:51 by tpotilli          #+#    #+#             */
/*   Updated: 2023/11/14 10:44:45 by tpotilli         ###   ########.fr       */
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

void	child_process_start(char *argv[], char *envp[], int *end)
{
	int	fd;

	close(end[0]);
	fd = ft_create_fd(argv[1], O_RDONLY);
	if (fd < 0)
		return (close(end[1]), exit(errno));
	if (dup2(fd, STDIN_FILENO) < 0)
		return (close(end[1]), close(fd), perror("dup2"), exit(errno));
	close(fd);
	if (dup2(end[1], STDOUT_FILENO) < 0)
		return (close(end[1]), perror("dup2"), exit(errno));
	close(end[1]);
	ft_do_process(envp, argv[2]);
}

void	child_process_end(char *argv[], char *envp[], int *end)
{
	int		fd;

	close (end[1]);
	if (dup2(end[0], STDIN_FILENO) < 0)
		return (close(end[0]), perror("dup2"), exit(errno));
	close(end[0]);
	fd = ft_create_fd(argv[4], O_WRONLY | O_CREAT | O_TRUNC);
	if (fd < 0)
		return (exit(errno));
	if (dup2(fd, STDOUT_FILENO) < 0)
		return (close(end[0]), close(fd), perror("dup2"), exit(errno));
	close (fd);
	ft_do_process(envp, argv[3]);
}
