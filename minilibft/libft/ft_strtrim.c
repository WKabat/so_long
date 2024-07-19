/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkabat <wkabat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:26:45 by wkabat            #+#    #+#             */
/*   Updated: 2024/03/15 10:20:50 by wkabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	str = 0;
	if (!s1)
		return (NULL);
	j = ft_strlen(s1);
	if (s1 != 0)
	{
		if (set != 0)
		{
			while (s1[i] && ft_strchr(set, s1[i]))
				i++;
			while (s1[j - 1] && ft_strchr(set, s1[j - 1]) && j > i)
				j--;
		}
		str = (char *)malloc(sizeof (char) * (j - i + 1));
		if (str == NULL)
			return (NULL);
		if (str)
			ft_strlcpy (str, &s1[i], j - i + 1);
	}
	return (str);
}
/*
#include <stdio.h>
int	main()
{
	char	str[] = "Hello, World!";
	char	*trim;

	trim = (ft_strtrim(str, "!Helod"));
	printf("%s\n", trim);
	free (trim);
	return (0);
}
*/