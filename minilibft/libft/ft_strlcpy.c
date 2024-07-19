/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkabat <wkabat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:47:31 by wkabat            #+#    #+#             */
/*   Updated: 2024/03/15 10:36:56 by wkabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = ft_strlen(src);
	if (size != 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (len);
}
/*
#include <string.h>
#include <stdio.h>
int	main(void)
{
	char	src[] = "Hello World!";
	char	dest[20];
	
	printf("Source string: %s\n", src);
	ft_strlcpy(dest, src, 6);
	printf("Dest: %s\n", dest);
	printf("The lenght: %zu\n", ft_strlcpy(dest, src, 3));
	return (0);
}
*/
