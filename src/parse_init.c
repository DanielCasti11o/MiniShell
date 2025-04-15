/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacastil <dacastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:49:00 by dacastil          #+#    #+#             */
/*   Updated: 2025/04/15 16:39:28 by dacastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Mini.h"

int	cases_builds(char *input)
{
	char	**split_in;

	split_in = ft_split(input, ' ');
	if (!ft_strncmp(split_in[0], "pwd", 4))
		return (fr_words(split_in), BUILD);
	else if (!ft_strncmp(split_in[0], "cd", 3))
		return (fr_words(split_in), BUILD);
	else if (!ft_strncmp(split_in[0], "echo", 4))
		return (fr_words(split_in), BUILD);
	else if (!ft_strncmp(split_in[0], "export", 6))
		return (fr_words(split_in), BUILD);
	else if (!ft_strncmp(split_in[0], "unset", 5))
		return (fr_words(split_in), BUILD);
	else if (!ft_strncmp(split_in[0], "env", 3))
		return (fr_words(split_in), BUILD);
	else if (!ft_strncmp(split_in[0], "exit", 5))
	{
		printf("exit\n");
		return (fr_words(split_in), exit(127), 0);
	}
	else
		return (COM);
}

// if (access(path, X_OK) == 0)
// 		{

int	cases_com(char *input, char **env)
{
	char	**split_com;
	char	**path;
	char	*line_p;
	int		i;

	path = ft_findpath(env);
	split_com = ft_split(input, ' ');
	i = 0;
	while (path[i])
	{
		line_p = creat_path(path[i], split_com[0]);
		if (!line_p)
			return (fr_words(path), fr_words(split_com),
				ft_error("ERROR: path\n", 1), ARG);
		if (access(line_p, X_OK) == 0)
			return (fr_words(path), fr_words(split_com), free(line_p), COM);
		free(line_p);
		i++;
	}
	fr_words(path);
	fr_words(split_com);
	return (ARG);
}

int	other_cases(char *input)
{
	char	**split_input;
	int		i;

	i = 0;
	if (!ft_strncmp(input, "<", 1) || !ft_strncmp(input, ">", 1)
		|| !ft_strncmp(input, "<<", 1) || !ft_strncmp(input, ">>", 1))
		return (RED);
	split_input = ft_split(input, ' ');
	while (split_input[i])
	{
		if ((ft_strncmp(split_input[i], "<", 1) == 0) && split_input[i - 1]
			|| (ft_strncmp(split_input[i], "<<", 2) == 0) && split_input[i - 1])
			return (fr_words(split_input), INFILE);
		else if ((ft_strncmp(split_input[i], ">", 1) == 0) && split_input[i + 1]
			|| (ft_strncmp(split_input[i], ">>", 2) == 0) && split_input[i + 1])
			return (fr_words(split_input), OUTFILE);
		i++;
	}
	fr_words(split_input);
	return (ARG);
}


int	parse(t_shell *mini, char **env)
{
	char	*input;
	int		value_token;

	input = mini->data_pt->input;
	if (input == NULL)
		ft_error("exit\n", 127);
	value_token = cases_builds(input);
	// printf ("token --> %d\n", value_token);
	if (value_token == BUILD)
		return (BUILD);
	value_token = cases_com(input, env);
	// printf ("token --> %d\n", value_token);
	if (value_token == COM)
		return (COM);
	else if (value_token == ARG)
		return (ARG);
	value_token = other_cases(input);
	if (value_token == RED)
		return (RED);
	else if (value_token == INFILE)
		return (INFILE);
	else if (value_token == OUTFILE)
		return (OUTFILE);
	else
		return (ARG);
}
