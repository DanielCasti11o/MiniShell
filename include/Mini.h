/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mini.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacastil <dacastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:11:26 by dacastil          #+#    #+#             */
/*   Updated: 2025/03/31 13:34:38 by dacastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_H
# define MINI_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include "../pipex/include/pipex.h"
# include "../pipex/libft_bonus/libft.h"
# include <signal.h>

typedef struct s_prompt
{
	char	*pwd;
	char	*user;
	char	*line_prompt;
}	t_prompt;

typedef struct s_shell
{
	t_prompt	*data_pt;
}	t_shell;


#endif
