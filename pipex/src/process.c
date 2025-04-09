/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel-castillo <daniel-castillo@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:16:28 by dacastil          #+#    #+#             */
/*   Updated: 2025/04/09 11:40:11 by daniel-cast      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include "../libft_bonus/libft.h"

char	**ft_findpath(char **envp)
{
	int		i;
	char	**wd;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
	{
		i++;
	}
	wd = ft_split((envp[i] + 5), ':');
	if (!wd)
		return (NULL);
	return (wd);
}

char	**process_c(char *command, char *trimm, char *str_arg, char **com_mk)
{
	char	**command_mask_new;
	int		i;

	(void)trimm;
	i = 0;
	while (com_mk[i])
		i++;
	command_mask_new = malloc((i + 1) * sizeof(char *));
	if (!command_mask_new)
		return (fr_words(com_mk), NULL);
	i = 1;
	command_mask_new[0] = command;
	while (com_mk[i])
	{
		command_mask_new[i] = ft_strtrim(com_mk[i], "'");
		if (!command_mask_new[i])
			return (free(str_arg), fr_words(com_mk), NULL);
		i++;
	}
	fr_words(com_mk);
	command_mask_new[i] = NULL;
	return (command_mask_new);
}

char	**split_command(char *arg, char *command)
{
	char	**command_mask;
	char	*str_arg;
	char	*trimm;

	trimm = NULL;
	str_arg = ft_strchr(arg, '\'');
	if (!str_arg)
	{
		command_mask = ft_split(arg, ' ');
		if (!command_mask)
			return (free(str_arg),
				ft_error("ERROR: Command invalid\n", 1), NULL);
		return (command_mask);
	}
	else
	{
		command_mask = ft_split(arg, ' ');
		command = ft_strdup(command_mask[0]);
		command_mask = process_c(command, trimm, str_arg, command_mask);
		if (!command_mask)
			return (free(command), free(trimm), NULL);
		return (command_mask);
	}
}

char	*creat_path(char	*path, char *argv)
{
	char	*result;
	char	*base_temp;

	if (ft_strchr(argv, '\''))
		return (ft_strdup(argv));
	base_temp = ft_strjoin(path, "/");
	if (!base_temp)
		return (NULL);
	result = ft_strjoin(base_temp, argv);
	if (!result)
		return (free(base_temp), NULL);
	free(base_temp);
	return (result);
}

void	exec_command(char **r_paths, char **command, char **envp)
{
	char	*path;
	int		i;

	i = 0;
	while (r_paths[i])
	{
		path = creat_path(r_paths[i], command[0]);
		if (!path)
			return (fr_words(r_paths), fr_words(command),
				fr_words(envp), ft_error("ERROR: path\n", 1));
		if (access(path, X_OK) == 0)
		{
			execve(path, command, envp);
		}
		free(path);
		i++;
	}
	if (r_paths)
		fr_words(r_paths);
	fr_words(command);
	ft_error("ERROR: Invalid command\n", 1);
}
