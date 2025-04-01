/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mini.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbolivar <sbolivar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:11:30 by dacastil          #+#    #+#             */
/*   Updated: 2025/04/01 16:27:44 by sbolivar         ###   ########.fr       */
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
	if (mini->data_pt->line_prompt == NULL)
		printf("exit");
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
