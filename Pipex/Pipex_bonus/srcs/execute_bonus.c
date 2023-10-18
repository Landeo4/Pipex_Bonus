/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 09:19:12 by tpotilli          #+#    #+#             */
/*   Updated: 2023/10/18 17:27:40 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_do_process_bonus(t_struct *list, char *cmd)
{
	int		i;
	char	**path;
	char	**cmd_argument;

	i = 0;
	cmd_argument = ft_split(cmd, ' ');
	path = ft_get_path_bonus(list->envp);
	while (path[i])
	{
		path[i] = str_join_free_bonus(path[i], "/");
		path[i] = ft_strjoin(path[i], cmd_argument[0]);
		execve(path[i], cmd_argument, list->envp);
		i++;
	}
	ft_freedb_bonus(path);
	ft_freedb_bonus(cmd_argument);
}

char	**ft_get_path_bonus(char **env)
{
	int		i;
	char	**path;

	i = 0;
	while (ft_strncmp(env[i], "PATH=", 5) != 0)
		i++;
	if (!env[i])
		perror("Error: PATH not found");
	path = ft_split(env[i] + 5, ':');
	return (path);
}

char *str_join_free_bonus(char *path, char *cmd)
{
	char *str;
	
	str = ft_strjoin(path, cmd);
	free(path);
	return (str);
}

void	ft_freedb_bonus(char **str)
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

/*void	ft_do_process(char *envp[], char *cmd, char *path[])
{
	int		i;
	char	**cmdarg;
	char	*fullpath;

	i = -1;
	cmdarg = ft_split(cmd, ' ');
	while (path[++i])
	{
		fullpath = ft_strjoin(path[i], cmd);
		if (!fullpath)
		{
			ft_freedb(cmdarg);
			return ;
		}
		execve(fullpath, cmdarg, envp);
		free(fullpath);
	}
	ft_freedb(cmdarg);
	write(1, "Command not found\n", 19);
}*/
