/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkabat <wkabat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:26:00 by wkabat            #+#    #+#             */
/*   Updated: 2024/03/15 10:12:45 by wkabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*holder;

	holder = (unsigned char *)b;
	while (len > 0)
	{
		*holder = (unsigned char)c;
		holder++;
		len--;
	}
	return (b);
}
/*
#include <stdio.h>

int	main(void)
{
	char	b[10];
	int		i;

	ft_memset(b, 'B', sizeof(b));
	i = 0;
	while (b[i++] != '\0')
	{
		printf("%c", b[i]);
	}
}
*/