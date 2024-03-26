/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauberna <pauberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:52:25 by pauberna          #+#    #+#             */
/*   Updated: 2024/03/26 16:25:31 by pauberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stddef.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"

typedef struct s_cmd
{
	char	**cmd;
	char	*path;
	char	*limiter;
	int		id;
	int		fd[2];
	int		cmd_nb;
}				t_cmd;

//path_utils.c
char	**path_creator(char **envp);
void	free_paths(char **paths);
void	path_checker(t_cmd *cmd, char **paths);
void	path_creator2(t_cmd *cmd, char **path, int n, int i);

//cmd_utils.c
void	free_cmd(t_cmd *cmd);
void	fill_cmd(t_cmd *cmd, char **av, char **envp);
void	cmd_initializer(t_cmd *cmd, char **av, int ac);
void	fill_cmd_the_sequel(t_cmd *cmd, char **envp, char *arg, int i);
t_cmd	*cmd_creator(int ac, char **av, char **envp);

//exec.c
int		exe_here_doc(t_cmd *cmd);
void	close_fd(t_cmd *cmd, int limit);
void	execute_fork(t_cmd *cmd, char **envp);
void	open_pipe(t_cmd *cmd, char **av, int ac);
void	execute_cmd(t_cmd *cmd, char **envp, int n);

//pipex.c
int		here_doc_checker(char **av);
void	fancy_exit(t_cmd *cmd);
void	error_msg(t_cmd *cmd, char *str, int n, int mode);

#endif