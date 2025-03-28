/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mini.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacastil <dacastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:11:30 by dacastil          #+#    #+#             */
/*   Updated: 2025/03/28 03:32:31 by dacastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Mini.h"
#include "../pipex/include/pipex.h"
#include "../pipex/libft_bonus/libft.h"

int	main(int argc, char **argv, char **env)
{
	int		i;
	char	*line_prompt;
	char	*user;
	char	*pwd;

	i = 0;
	user = getenv("USER");
	pwd = getenv("PWD");
	user = ft_strjoin(user, "-");
	user = ft_strjoin(user, pwd);
	line_prompt = readline(user);
	while (line_prompt != NULL)
	{
		printf("-->> %s\n", line_prompt);
		line_prompt = readline(user);
	}
	// while (env[i])
	// {
	// 	printf("--> %s\n", env[i]);
	// 	i++;
	// }
	return (0);
}

