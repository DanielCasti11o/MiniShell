/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacastil <dacastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:53:29 by dacastil          #+#    #+#             */
/*   Updated: 2025/03/20 21:19:34 by dacastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <string.h>
# include <fcntl.h>
# include "../libft_bonus/libft.h"

typedef struct s_pid
{
	pid_t	pid1;
	int		pipefd[2]; // extremos read & write
}	t_pid;

void	create_process(t_pid *process, char **argv, char **envp);
void	red_input(char *infile, t_pid *process);
void	red_output(char *outfile, t_pid *process);
void	process_command(char **envp, char **argv, int ix_argv);
char	**ft_findpath(char **envp);
char	**split_command(char *arg, char *command);
void	fr_words(char **wds);
void	exec_command(char **r_paths, char **command, char **envp);
char	*creat_path(char	*path, char *argv);
void	ft_error(char *msg, int flag);
char	**process_c(char *command, char *trimm, char *str_arg, char **com_mk);
void	ft_putstr(char *s);

#endif
