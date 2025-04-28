/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mini.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel-castillo <daniel-castillo@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:11:26 by dacastil          #+#    #+#             */
/*   Updated: 2025/04/21 14:39:17 by daniel-cast      ###   ########.fr       */
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

enum	e_type_tok
{
	COM,
	BUILD,
	RED,
	ARG,
	PIPE,
	INFILE,
	OUTFILE,
};

typedef struct s_prompt
{
	char	*pwd;
	char	*user;
	char	*input;

}	t_prompt;


// Permisos totales para 0644
//     Esto significa:
//     Propietario: Puede leer y escribir (rw-).
    // Grupo: Solo puede leer (r--).
    // Otros: Solo pueden leer (r--).

typedef struct s_parser
{
	char		**command; // comando con su arg
	char		*input;		// infile
	char		*output;	// outfile

	t_parser	*next; // -->

}	t_parser;

typedef struct s_shell
{
	t_prompt	*data_pt;
	pid_t		pid_com;
	char		**path;

}	t_shell;


	// --------------
	// [ QUE ES PID_T]
	// --------------
	// identificador de proceso hijo que se usará para los comandos,
	// ya que para realizar un comando debemos crear un proceso hijo que lo ejecute para que el padre que es el programa de la mini lo muestre

t_shell	*build_factory(void);
void	ft_signals(void);
void	ctrl_c(int sign);
void	ft_buildings(t_shell *mini);
void	ft_prompt(t_shell *mini, char **env);
int		parse(t_shell *mini, char **env);
int		cases_builds(char *input);
int		cases_com(char *input, char **env);
int		other_cases(char *input);
void	posible_cases(t_shell *mini, int flag, char **env);
void	redirects(t_shell *mini);

#endif
