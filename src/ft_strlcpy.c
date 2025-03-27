/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacastil <dacastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:47:35 by dacastil          #+#    #+#             */
/*   Updated: 2025/03/27 19:46:10 by dacastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include "../include/Mini.h"

int	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[j] != '\0')
	{
		j++;
	}
	if (size == 0)
		return (j);
	while (i < (size - 1) && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (j);
}
/*
int main()
{

	char dst[20] = "";
	const char src[] = "Adios";
	size_t n = 4;

	printf("%d\n", ft_strlcpy(dst, src, n));
	return 0;
}
*/
