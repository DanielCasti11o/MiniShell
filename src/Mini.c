/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mini.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbolivar <sbolivar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:11:30 by dacastil          #+#    #+#             */
/*   Updated: 2025/03/28 03:17:16 by sbolivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Mini.h"

int g_exit = 0;

void	manejador_signt(int sig)
{
	g_exit = 130;
	printf("\n\033[32mMiniShell:\033[0m");
}

char	*ft_mini(int argc, char **argv, char **env)
{
	int		i;
	char	*line_prompt;
	char	*pwd;

	i = 0;
	pwd = getenv("PWD");
	line_prompt = readline("\033[32mMiniShell:\033[0m");
	while (line_prompt != NULL)
	{
		printf("-->> %s\n", line_prompt);
		line_prompt = readline("\033[32mMiniShell:\033[0m");
	}
	return (line_prompt);
}

int	main(int argc, char **argv, char **env)
{
	signal(SIGINT, manejador_signt);
	ft_mini(argc, argv, env);
	return (g_exit);
}
