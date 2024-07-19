/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkabat <wkabat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 19:26:48 by wkabat            #+#    #+#             */
/*   Updated: 2024/03/15 10:37:13 by wkabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!dst && size == 0)
		return ((ft_strlen(src)));
	while (dst[i] && i < size)
		i++;
	if (i == size)
		return (size + ft_strlen(src));
	while (src[j] && (i + j + 1) < size)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i + j < size)
		dst[i + j] = '\0';
	return (i + ft_strlen(src));
}

/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	src[] = "Hello, World!";
	//char	dest[30];

	printf("%zu\n", ft_strlcat(dest, src, 12));
	return (0);
}
*/