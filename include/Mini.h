/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mini.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbolivar <sbolivar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:11:26 by dacastil          #+#    #+#             */
/*   Updated: 2025/03/28 03:09:07 by sbolivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_H
# define MINI_H

# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

extern int	g_exit;

char		*ft_strjoin(char const *s1, char const *s2);
int			ft_strlen(const char *s);
int			ft_strlcpy(char *dst, const char *src, size_t size);

#endif
