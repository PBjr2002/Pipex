/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:52:14 by pauberna          #+#    #+#             */
/*   Updated: 2024/03/12 12:29:48 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	fancy_exit(t_cmd *cmd)
{
	perror("Error");
	free_cmd(cmd);
	exit(EXIT_FAILURE);
}

void	error_msg(t_cmd *cmd, int mode)
{
	if (mode == 0)
		ft_putstr_fd("1st file not found\n", 1);
	else if (mode == 1)
		ft_putstr_fd("Coudnt creat the outfile\n", 1);
	fancy_exit(cmd);
}

int	main(int ac, char **av, char **envp)
{
	t_cmd	*cmd;

	if (ac < 5)
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
