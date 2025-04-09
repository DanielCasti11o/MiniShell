/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mini.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel-castillo <daniel-castillo@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:11:26 by dacastil          #+#    #+#             */
/*   Updated: 2025/04/09 11:55:20 by daniel-cast      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_H
# define MINI_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include "../pipex/include/pipex.h"
# include "../pipex/libft_bonus/libft.h"
# include <signal.h>

typedef struct s_prompt
{
	char	*pwd;
	char	*user;
	char	*input;
}	t_prompt;

typedef struct s_shell
{
	t_prompt	*data_pt;

	// --------------
	// [ QUE ES PID_T]
	// --------------
	// identificador de proceso hijo que se usará para los comandos,
	// ya que para realizar un comando debemos crear un proceso hijo que lo ejecute para que el padre que es el programa de la mini lo muestre
	pid_t       pid_com; 
}	t_shell;

void	ft_signals(void);
void	ctrl_c(int sign);
void	ft_buildings(t_shell *mini);
void	ft_prompt(t_shell *mini, char **env);

#endif
