/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbolivar <sbolivar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:36:09 by sbolivar          #+#    #+#             */
/*   Updated: 2025/04/02 03:16:02 by sbolivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Mini.h"

void	ft_cd(char	**dir, t_shell *mini)
{
	if (dir[1] == NULL || !ft_strncmp(dir[0], "", 2))
		dir[1] = getenv("HOME");
	if (chdir(dir[1]) == -1)
	{
		perror("Error al cambiar de directorio");
		return ;
	}
	mini->data_pt->pwd = getcwd(NULL, 0);
	mini->data_pt->user = "\033[44;97m@MINISHELL\033[0m \033[38;5;82m";
	mini->data_pt->user = ft_strjoin(mini->data_pt->user, "-");
	mini->data_pt->user = ft_strjoin(mini->data_pt->user, getcwd(NULL, 0));
	mini->data_pt->user = ft_strjoin(mini->data_pt->user, " ~ \033[0;0m");
}

void	ft_buildings(t_shell *mini)
{
	int		i;
	char	**dir;

	dir = ft_split(mini->data_pt->input, ' ');
	i = 0;
	if (!ft_strncmp(dir[0], "pwd", 4))
		printf("%s\n", mini->data_pt->pwd);
	if (!ft_strncmp(dir[0], "cd", 3))
		ft_cd(dir, mini);
	if (!ft_strncmp(dir[0], "exit", 5))
	{
		printf("exit\n");
		exit(0);
	}
	return ;
}
