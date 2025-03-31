/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mini.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacastil <dacastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:11:30 by dacastil          #+#    #+#             */
/*   Updated: 2025/03/31 14:31:06 by dacastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Mini.h"
#include "../pipex/include/pipex.h"
#include "../pipex/libft_bonus/libft.h"
#include <signal.h>

//	----------- Sí quiere ver los env dentro de un programa main ----------

	// while (env[i])
	// {
	// 	printf("--> %s\n", env[i]);
	// 	i++;
	// }

//
// --------------------------------------------------------------
//		REGLAS DE DISEÑO PARA EL PROMPT U OTRAS COSITAS
//		COLORES, SUBRAYADO Y CAMBIO DE FONDO EN EL TEXTO
//---------------------------------------------------------------
//	\033[4;38;5;52m  ----> subraya rojo

//	\033[48;5;52m  -----> resalta rojo  ---> verde \033[48;5;22;97m

// -----------------------------------------------------------------------------------------------------------------------

// Ideas de implementacion para añadir una estructura y
//usar tecnica de shell factory, PATRONES DE DISEÑO

/*


-----------------
   SHELL FACTORY     |
-----------------    V



Estaba intentando meter esto del prompt con la nueva implementacion de la estructura pero
me estaba dando unos segfaults que tengo que revisar para poder seguir mirandolo.

-----------------
	PROMPT
-----------------

void	ft_prompt(t_shell *mini)
{
	mini->data_pt->user = ft_strjoin(mini->data_pt->user, getenv("USER"));
	mini->data_pt->user = ft_strjoin(mini->data_pt->user, "\033[0m \033[38;5;82m");
	mini->data_pt->user = ft_strjoin(mini->data_pt->user, "-");
	mini->data_pt->user = ft_strjoin(mini->data_pt->user, mini->data_pt->pwd);
	mini->data_pt->user = ft_strjoin(mini->data_pt->user, " ~ \033[0;0m");
	mini->data_pt->line_prompt = readline(mini->data_pt->user);
	while (mini->data_pt->line_prompt != NULL)
	{
		printf("%s\n", mini->data_pt->line_prompt);
		mini->data_pt->line_prompt = readline(mini->data_pt->user);
	}

}
-----------------------------------------------------------------------------------------------------------------
*/


t_shell	*build_factory(void)
{
	t_shell	*new;

	new = malloc(sizeof(t_shell));
	if (!new)
		return (NULL);
	new->data_pt = malloc(sizeof(t_prompt));
	if (!new->data_pt)
		return (NULL);
	new->data_pt->line_prompt = NULL;
	new->data_pt->pwd = getenv("PWD");
	new->data_pt->user = "\033[44;97m";
	return (new);
}

void	ft_prompt(t_shell *mini)
{
	mini->data_pt->user = ft_strjoin(mini->data_pt->user, "@MINISHELL");
	mini->data_pt->user = ft_strjoin(mini->data_pt->user, "\033[0m \033[38;5;82m");
	mini->data_pt->user = ft_strjoin(mini->data_pt->user, "-");
	mini->data_pt->user = ft_strjoin(mini->data_pt->user, mini->data_pt->pwd);
	mini->data_pt->user = ft_strjoin(mini->data_pt->user, " ~ \033[0;0m");
	mini->data_pt->line_prompt = readline(mini->data_pt->user);
	while (mini->data_pt->line_prompt != NULL)
	{
		printf("%s\n", mini->data_pt->line_prompt);
		mini->data_pt->line_prompt = readline(mini->data_pt->user);
	}

}

void	sigint_handler(int sign)
{
	(void)sign;
	write(1, "\n", 1);
	rl_on_new_line();    // Indica que hay una nueva línea (obligatorio para readline)
	rl_replace_line("", 0); // Limpia la línea actual en el prompt
	rl_redisplay();
}


void ft_signals(void)
{
    struct sigaction sa;

    sa.sa_handler = sigint_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if (sigaction(SIGINT, &sa, NULL) == -1)
    {
        perror("Signal failed\n");
        exit(1);
    }
}



int	main(int argc, char **argv, char **env)
{
	t_shell	*mini;
	int		i;

	i = 0;
	ft_signals();
	mini = build_factory();
	ft_prompt(mini);
	return (0);
}

