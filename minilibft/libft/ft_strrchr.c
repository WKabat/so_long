/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkabat <wkabat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:06:55 by wkabat            #+#    #+#             */
/*   Updated: 2024/03/15 10:31:07 by wkabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	j;

	i = ft_strlen(s);
	j = c;
	if (j == '\0')
		return ((char *) s + i);
	while (i >= 0)
	{
		if (s[i] == j)
			return ((char *)s + i);
		i--;
	}
	return (0);
}
/*
#include <stdio.h>
int	main(void)
{
	char	str[] = "abc";
	int	c = 'a';
	printf("%s\n", ft_strrchr(str, c));
	return (0);
}
*/