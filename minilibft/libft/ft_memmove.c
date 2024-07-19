/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkabat <wkabat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:35:28 by wkabat            #+#    #+#             */
/*   Updated: 2024/03/15 10:47:40 by wkabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*temp1;
	unsigned char	*temp2;

	temp1 = (unsigned char *) dst;
	temp2 = (unsigned char *) src;
	if (dst < src)
		while (len--)
			*temp1++ = *temp2++;
	else if (dst > src)
		while (len--)
			temp1[len] = temp2[len];
	return (dst);
}
/*
#include <string.h>
#include <stdio.h>
int	main(void)
{
	char	src1[] = "Hello, World!";
	char	src2[] = "Hello, World!";
	char	dst1[] = "Goodbye, World!";
	char	dst2[] = "Goodbye, World!";
	memmove(dst1, src1, 10);
	printf ("After memmove= %s\n", dst1);
	ft_memmove(dst2, src2, 10);
	printf ("After ft_memmove = %s\n", dst2);
	return (0);
}
*/