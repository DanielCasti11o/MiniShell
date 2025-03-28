/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mini.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacastil <dacastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:11:30 by dacastil          #+#    #+#             */
/*   Updated: 2025/03/28 16:37:59 by dacastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Mini.h"
#include "../pipex/include/pipex.h"
#include "../pipex/libft_bonus/libft.h"

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

int	build_factory(t_shell	*mini)
{
	mini = malloc(sizeof(t_shell));
	if (!mini)
		return (0);
	mini->data_prompt = malloc(sizeof(t_prompt));
	if (!mini->data_prompt)
		return (0);
	mini->data_prompt->line_prompt = NULL;
	mini->data_prompt->pwd = getenv("PWD");
	mini->data_prompt->user = "\033[44;97m";
	return (1);
}

Estaba intentando meter esto del prompt con la nueva implementacion de la estructura pero
me estaba dando unos segfaults que tengo que revisar para poder seguir mirandolo.

-----------------
	PROMPT
-----------------

void	ft_prompt(t_shell *mini)
{
	mini->data_prompt->user = ft_strjoin(mini->data_prompt->user, getenv("USER"));
	mini->data_prompt->user = ft_strjoin(mini->data_prompt->user, "\033[0m \033[38;5;82m");
	mini->data_prompt->user = ft_strjoin(mini->data_prompt->user, "-");
	mini->data_prompt->user = ft_strjoin(mini->data_prompt->user, mini->data_prompt->pwd);
	mini->data_prompt->user = ft_strjoin(mini->data_prompt->user, " ~ \033[0;0m");
	mini->data_prompt->line_prompt = readline(mini->data_prompt->user);
	while (mini->data_prompt->line_prompt != NULL)
	{
		printf("%s\n", mini->data_prompt->line_prompt);
		mini->data_prompt->line_prompt = readline(mini->data_prompt->user);
	}

}
-----------------------------------------------------------------------------------------------------------------
*/


void	ft_prompt(t_shell *mini)
{
}

int	main(int argc, char **argv, char **env)
{
	t_shell	*mini;
	int		i;
	char	*line_prompt;
	char	*user;
	char	*pwd;

	i = 0;

	user = "\033[44;97m";
	user = ft_strjoin(user, getenv("USER"));
	pwd = getenv("PWD");
	user = ft_strjoin(user, "\033[0m \033[38;5;82m");
	user = ft_strjoin(user, "-");
	user = ft_strjoin(user, pwd);
	user = ft_strjoin(user, " ~ \033[0;0m");
	line_prompt = readline(user);
	while (line_prompt != NULL)
	{
		printf("%s\n", line_prompt);
		line_prompt = readline(user);
	}
	return (0);
}

