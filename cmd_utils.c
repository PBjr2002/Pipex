/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:51:18 by pauberna          #+#    #+#             */
/*   Updated: 2024/03/12 11:15:55 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_cmd(t_cmd *cmd)
{
	int	n;
	int	i;

	n = 0;
	if (!cmd)
		return ;
	while (n <= cmd[0].cmd_nb)
	{
		if (cmd[n].cmd)
		{
			i = 0;
			while (cmd[n].cmd && cmd[n].cmd[i])
			{
				if (cmd[n].cmd[i])
					free(cmd[n].cmd[i]);
				i++;
			}
			free(cmd[n].cmd);
		}
		if (cmd[n].path)
			free(cmd[n].path);
		n++;
	}
	free(cmd);
}

void	cmd_initializer(t_cmd *cmd, int ac)
{
	cmd->cmd = NULL;
	cmd->path = NULL;
	cmd->fd[0] = 0;
	cmd->fd[1] = 0;
	cmd[0].cmd_nb = ac - 3;
}

t_cmd	*cmd_creator(int ac, char **av, char **envp)
{
	t_cmd	*cmd;
	char	**paths;
	int		i;

	cmd = malloc(sizeof(t_cmd) * (ac - 2));
	if (!cmd)
		fancy_exit(cmd);
	cmd_initializer(cmd, ac);
	i = 1;
	paths = path_creator(envp);
	if (!paths)
		fancy_exit(cmd);
	while (i < ac - 2)
	{
		cmd[i].cmd = ft_split(av[i + 1], ' ');
		if (!cmd[i].cmd)
			fancy_exit(cmd);
		cmd[i].path = NULL;
		i++;
	}
	path_checker(cmd, paths);
	return (cmd);
}
