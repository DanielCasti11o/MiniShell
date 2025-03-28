/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacastil <dacastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:37:20 by dacastil          #+#    #+#             */
/*   Updated: 2024/10/01 18:29:39 by dacastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	strlng;
	char	*subst;

	strlng = ft_strlen(s);
	if (start >= strlng)
	{
		return (ft_strdup(""));
	}
	if (len > (strlng - start))
	{
		len = (strlng - start);
	}
	subst = (char *)malloc((len + 1) * sizeof(char));
	if (!subst)
	{
		return (NULL);
	}
	ft_strlcpy(subst, (s + start), (len + 1));
	return (subst);
}
