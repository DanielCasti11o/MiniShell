/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacastil <dacastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:49:00 by dacastil          #+#    #+#             */
/*   Updated: 2025/04/14 20:14:34 by dacastil         ###   ########.fr       */
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

int	cases_com(char *input, char **env)
{
	char	**split_com;

	split_com = ft_split(input, '|');
	if (execve(input, split_com, env) == -1)
		return (fr_words(split_com), ARG);
	else
		return (COM);
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
		if ((split_input[i] == "<" && split_input[i - 1])
			|| (split_input[i] == "<<" && split_input[i - 1]))
			return (fr_words(split_input), INFILE);
		else if (split_input[i] == ">" && split_input[i + 1]
			|| (split_input[i] == ">>" && split_input[i + 1]))
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
	printf ("token --> %d\n", value_token);
	if (value_token == BUILD)
		return (BUILD);
	value_token = cases_com(input, env);
	printf ("token --> %d\n", value_token);
	if (value_token == COM)
		return (COM);
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
