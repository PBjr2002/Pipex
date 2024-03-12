/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:15:38 by pauberna          #+#    #+#             */
/*   Updated: 2024/03/12 10:30:22 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**path_creator(char **envp)
{
	char	**path;
	int		i;
	int		index;

	path = NULL;
	index = 0;
	while (envp[index])
	{
		if (ft_strncmp(envp[index], "PATH=", 5) == 0)
		{
			i = 0;
			path = ft_split(envp[index], ':');
			if (!path)
				free_paths(path);
			else
				path[0] = path[0] + 5;
			break ;
		}
		index++;
	}
	return (path);
}

void	free_paths(char **paths)
{
	int	i;

	i = 0;
	while (paths[i])
	{
		if (i == 0)
			free(paths[i] - 5);
		else
			free(paths[i]);
		i++;
	}
	free(paths);
}

void	path_checker(t_cmd *cmd, char **paths)
{
	int	i;
	int	n;

	n = 1;
	while (n <= cmd[0].cmd_nb)
	{
		i = 0;
		while (paths && paths[i])
		{
			path_creator2(cmd, paths, n, i);
			if (access(cmd[n].path, X_OK) == 0)
				break ;
			else
				free(cmd[n].path);
			i++;
		}
		if (!paths[i])
		{
			cmd[n].path = NULL;
			free_paths(paths);
			fancy_exit(cmd);
		}
		n++;
	}
	free_paths(paths);
}

void	path_creator2(t_cmd *cmd, char **path, int n, int i)
{
	char	*tmp;

	tmp = ft_strjoin(path[i], "/");
	if (!tmp)
	{
		free_paths(path);
		fancy_exit(cmd);
	}
	cmd[n].path = ft_strjoin(tmp, cmd[n].cmd[0]);
	if (!cmd[n].path)
	{
		free_paths(path);
		fancy_exit(cmd);
	}
	free(tmp);
}
