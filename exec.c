/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:02:09 by pauberna          #+#    #+#             */
/*   Updated: 2024/03/12 12:28:30 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_fd(t_cmd *cmd, int limit)
{
	int	n;

	n = 0;
	while (n < limit)
	{
		close(cmd[n].fd[0]);
		close(cmd[n].fd[1]);
		n++;
	}
}

void	execute_fork(t_cmd *cmd, char **envp)
{
	int	n;

	n = 0;
	while (++n <= cmd[0].cmd_nb)
	{
		if (cmd[n].path)
		{
			cmd[n].id = fork();
			if (cmd[n].id == -1)
				fancy_exit(cmd);
			if (cmd[n].id == 0)
			{
				if (access(cmd[n].path, X_OK) == 0)
					execute_cmd(cmd, envp, n);
				break ;
			}
		}
	}
	close_fd(cmd, cmd[0].cmd_nb);
}

void	open_pipe(t_cmd *cmd, char **av, int ac)
{
	int	n;

	cmd[0].fd[0] = open(av[1], O_RDONLY);
	if (cmd[0].fd[0] == -1)
		error_msg(cmd, 0);
	cmd[0].fd[1] = open(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (cmd[0].fd[1] == -1)
		error_msg(cmd, 1);
	n = 1;
	while (n < cmd[0].cmd_nb)
	{
		if (pipe(cmd[n].fd) == -1)
			fancy_exit(cmd);
		n++;
	}
}

void	execute_cmd(t_cmd *cmd, char **envp, int n)
{
	if (dup2(cmd[n - 1].fd[0], STDIN_FILENO) == -1)
	{
		close_fd(cmd, cmd[0].cmd_nb);
		fancy_exit(cmd);
	}
	if (n == cmd[0].cmd_nb)
	{
		if (dup2(cmd[0].fd[1], STDOUT_FILENO) == -1)
		{
			close_fd(cmd, cmd[0].cmd_nb);
			fancy_exit(cmd);
		}
	}
	else
	{
		if (dup2(cmd[n].fd[1], STDOUT_FILENO) == -1)
		{
			close_fd(cmd, cmd[0].cmd_nb);
			fancy_exit(cmd);
		}
	}
	close_fd(cmd, cmd[0].cmd_nb);
	if (execve(cmd[n].path, cmd[n].cmd, envp) == -1)
		fancy_exit(cmd);
}
