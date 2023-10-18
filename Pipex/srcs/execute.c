/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 09:19:12 by tpotilli          #+#    #+#             */
/*   Updated: 2023/10/18 13:45:39 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_do_process(char *envp[], char *cmd)
{
	int		i;
	char	**path;
	char	**cmd_argument;

	i = 0;
	cmd_argument = ft_split(cmd, ' ');
	path = ft_get_path(envp);
	while (path[i])
	{
		path[i] = str_join_free(path[i], "/");
		path[i] = ft_strjoin(path[i], cmd_argument[0]);
		execve(path[i], cmd_argument, envp);
		i++;
	}
	ft_freedb(path);
	ft_freedb(cmd_argument);
}

char	**ft_get_path(char **env)
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

char *str_join_free(char *path, char *cmd)
{
	char *str;
	
	str = ft_strjoin(path, cmd);
	free(path);
	return (str);
}

void	ft_freedb(char **str)
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
