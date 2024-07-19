/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkabat <wkabat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:52:37 by wkabat            #+#    #+#             */
/*   Updated: 2024/03/15 10:37:48 by wkabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*nstr;
	size_t	i;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	nstr = (char *)malloc(sizeof(char) * (ft_strlen (s1) + ft_strlen (s2) + 1));
	if (nstr == 0)
		return (NULL);
	while (*s1)
		nstr[i++] = *s1++;
	while (*s2)
		nstr[i++] = *s2++;
	nstr[i] = 0;
	return (nstr);
}
/*
#include <stdio.h>

int	main()
{
	char	str1[] = "Hello ";
	char	str2[] = "World!";
	char	*nstr;

	nstr = ft_strjoin(str1, str2);
	printf("%s\n", nstr);
	free (nstr);
	return (0);
}
*/