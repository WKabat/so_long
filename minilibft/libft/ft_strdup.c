/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkabat <wkabat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:32:08 by wkabat            #+#    #+#             */
/*   Updated: 2024/03/15 10:38:34 by wkabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = ft_strlen(s);
	str = (char *)malloc(sizeof (*str) * (j + 1));
	if (str == NULL)
		return (NULL);
	while (i < j)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
#include <string.h>
#include <stdlib.h>
int	main()
{
	char	str1[] = "Hello World!";
	char	*str2;
	char	*str3;

	str2 = strdup(str1);
	str3 = ft_strdup(str1);
	printf("%s\n", str2);
	printf("%s\n", str3);
	free (str2);
	free (str3);
	return (0);
}
*/