/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:02:09 by pauberna          #+#    #+#             */
/*   Updated: 2024/03/21 14:37:25 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	exe_here_doc(t_cmd *cmd)
{
	char	*str;
	int		fd[2];

	if (pipe(fd) == -1)
		fancy_exit(cmd);
	while (1)
	{
		str = get_next_line(STDIN_FILENO);
		if (!str)
			fancy_exit(cmd);
		if (ft_strncmp(str, cmd[0].limiter, ft_strlen(str) - 1) == 0
			&& (ft_strlen(str) - 1) == ft_strlen(cmd[0].limiter))
			break ;
		ft_putstr_fd(str, fd[1]);
		free(str);
	}
	free(str);
	close(fd[1]);
	free(cmd[0].limiter);
	return (fd[0]);
}

void	close_fd(t_cmd *cmd, int limit)
{
	int	n;

	n = 0;
	while (n < limit)
	{
		if (cmd[n].fd[0] != -1 && cmd[n].fd[0] != STDIN_FILENO
			&& cmd[n].fd[0] != STDOUT_FILENO && cmd[n].fd[0] != STDERR_FILENO)
			close(cmd[n].fd[0]);
		if (cmd[n].fd[1] != -1 && cmd[n].fd[1] != STDIN_FILENO
			&& cmd[n].fd[1] != STDOUT_FILENO && cmd[n].fd[1] != STDERR_FILENO)
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
		if ((!cmd[n].path || !cmd[n].path[0]) && cmd[n].cmd)
			error_msg(cmd, NULL, n, 0);
	}
	close_fd(cmd, cmd[0].cmd_nb);
}

void	open_pipe(t_cmd *cmd, char **av, int ac)
{
	int	n;

	if (here_doc_checker(av) == 0)
	{
		cmd[0].fd[0] = exe_here_doc(cmd);
		cmd[0].fd[1] = open(av[ac - 1], O_CREAT | O_WRONLY | O_APPEND, 0644);
	}
	else
	{
		cmd[0].fd[0] = open(av[1], O_RDONLY);
		cmd[0].fd[1] = open(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	}
	if (cmd[0].fd[1] == -1)
		fancy_exit(cmd);
	if (cmd[0].fd[0] == -1)
		error_msg(cmd, av[1], 0, 2);
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
		error_msg(cmd, NULL, 0, 1);
	if (n == cmd[0].cmd_nb)
	{
		if (dup2(cmd[0].fd[1], STDOUT_FILENO) == -1)
			error_msg(cmd, NULL, 0, 1);
	}
	else
	{
		if (dup2(cmd[n].fd[1], STDOUT_FILENO) == -1)
			error_msg(cmd, NULL, 0, 1);
	}
	close_fd(cmd, cmd[0].cmd_nb);
	if (execve(cmd[n].path, cmd[n].cmd, envp) == -1)
		fancy_exit(cmd);
}
