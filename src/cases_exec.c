/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacastil <dacastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:16:01 by dacastil          #+#    #+#             */
/*   Updated: 2025/04/15 15:04:22 by dacastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Mini.h"

void	posible_cases(t_shell *mini, int flag, char **env)
{
	int		status;
	char	**com;

	// printf("flag = %d", flag);
	if (flag == BUILD)
		ft_buildings(mini);
	else if (flag == COM)
	{
		mini->pid_com = fork();
		if (mini->pid_com < 0)
			ft_error("ERROR: child no created\n", 1);
		if (mini->pid_com == 0)
		{
			com = ft_split(mini->data_pt->input, '|');
			process_command(env, com, 0);
		}
		waitpid(mini->pid_com, &status, 0);
	}
// 	if (flag == RED)
// 		redirects(mini);
}
