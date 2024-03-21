/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:51:18 by pauberna          #+#    #+#             */
/*   Updated: 2024/03/21 14:40:21 by pauberna         ###   ########.fr       */
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

void	fill_cmd(t_cmd *cmd, char **av, char **envp)
{
	int	i;

	i = 1;
	while (i <= cmd[0].cmd_nb)
	{
		if (here_doc_checker(av) == 0)
			fill_cmd_the_sequel(cmd, envp, av[i + 2], i);
		else
			fill_cmd_the_sequel(cmd, envp, av[i + 1], i);
		i++;
	}
}

void	cmd_initializer(t_cmd *cmd, char **av, int ac)
{
	int	i;

	if (here_doc_checker(av) == 0)
		cmd[0].cmd_nb = ac - 4;
	else
		cmd[0].cmd_nb = ac - 3;
	i = 0;
	while (i <= cmd[0].cmd_nb)
	{
		cmd[i].cmd = NULL;
		cmd[i].path = NULL;
		cmd[i].fd[0] = 0;
		cmd[i].fd[1] = 0;
		i++;
	}
}

void	fill_cmd_the_sequel(t_cmd *cmd, char **envp, char *arg, int i)
{
	if (ft_strncmp(arg, "/", 1) == 0)
	{
		if (access(arg, X_OK) == 0)
		{
			if (!envp || !envp[0])
				cmd[i].path = ft_strdup(arg);
			cmd[i].cmd = malloc (sizeof(char *) * 2);
			cmd[i].cmd[0] = ft_strdup(ft_strrchr(arg, '/') + 1);
			cmd[i].cmd[1] = NULL;
		}
		else
		{
			ft_putstr_fd("command not found : ", 2);
			ft_putendl_fd(arg, 2);
		}
	}
	else
	{
		cmd[i].cmd = ft_split(arg, ' ');
		if (!cmd[i].cmd || !cmd[i].cmd[0])
			error_msg(cmd, arg, i, 3);
		cmd[i].path = NULL;
	}
}

t_cmd	*cmd_creator(int ac, char **av, char **envp)
{
	t_cmd	*cmd;
	char	**paths;

	cmd = malloc(sizeof(t_cmd) * (ac - 2));
	if (!cmd)
		fancy_exit(cmd);
	cmd_initializer(cmd, av, ac);
	if (here_doc_checker(av) == 0)
		cmd[0].limiter = ft_strdup(av[2]);
	fill_cmd(cmd, av, envp);
	paths = path_creator(envp);
	path_checker(cmd, paths);
	return (cmd);
}
