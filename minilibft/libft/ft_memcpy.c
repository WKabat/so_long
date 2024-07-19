/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkabat <wkabat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 12:23:29 by wkabat            #+#    #+#             */
/*   Updated: 2024/03/15 10:48:04 by wkabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	if (!dest && !src)
		return (0);
	while (n--)
		((char *)dest)[n] = ((char *)src)[n];
	return (dest);
}
/*
#include <string.h>
int	main(void)
{
	char	src[] = "Hello";
	char	dst[] = "World";
	
	printf("Before: %s\n", dst);
	memcpy (dst, src, 3);
	printf("After: %s\n", dst);
	return (0);
}
*/
