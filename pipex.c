/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:52:14 by pauberna          #+#    #+#             */
/*   Updated: 2024/03/21 14:39:43 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	here_doc_checker(char **av)
{
	if (ft_strcmp(av[1], "here_doc") == 0)
		return (0);
	return (-1);
}

void	fancy_exit(t_cmd *cmd)
{
	if (cmd[0].fd[0] != -1 && cmd[0].fd[0] != STDIN_FILENO
		&& cmd[0].fd[0] != STDOUT_FILENO && cmd[0].fd[0] != STDERR_FILENO)
		close(cmd[0].fd[0]);
	if (cmd[0].fd[1] != -1 && cmd[0].fd[1] != STDIN_FILENO
		&& cmd[0].fd[1] != STDOUT_FILENO && cmd[0].fd[1] != STDERR_FILENO)
		close(cmd[0].fd[1]);
	perror("Error");
	free_cmd(cmd);
	exit(EXIT_FAILURE);
}

void	error_msg(t_cmd *cmd, char *str, int n, int mode)
{
	if (mode == 0)
	{
		cmd[n].path = NULL;
		ft_putstr_fd("command not found : ", 2);
		ft_putendl_fd(cmd[n].cmd[0], 2);
	}
	else if (mode == 1)
	{
		close_fd(cmd, cmd[0].cmd_nb);
		free_cmd(cmd);
		exit(EXIT_FAILURE);
	}
	else if (mode == 2)
	{
		ft_putstr_fd("no such file or directory : ", 2);
		ft_putendl_fd(str, 2);
	}
	else if (mode == 3)
	{
		cmd[n].path = NULL;
		free(cmd[n].cmd);
		cmd[n].cmd = NULL;
		ft_putstr_fd("command not found : ", 2);
		ft_putendl_fd(str, 2);
	}
}

int	main(int ac, char **av, char **envp)
{
	t_cmd	*cmd;

	if (here_doc_checker(av) == 0 && ac < 6)
	{
		ft_putstr_fd("Invalid Number of Arguments\n", 1);
		return (0);
	}
	else if (ac < 5)
	{
		ft_putstr_fd("Invalid Number of Arguments\n", 1);
		return (0);
	}
	cmd = cmd_creator(ac, av, envp);
	if (!cmd)
		fancy_exit(cmd);
	open_pipe(cmd, av, ac);
	execute_fork(cmd, envp);
	close_fd(cmd, cmd[0].cmd_nb);
	free_cmd(cmd);
	return (0);
}
