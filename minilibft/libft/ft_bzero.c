/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkabat <wkabat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:43:42 by wkabat            #+#    #+#             */
/*   Updated: 2024/03/15 10:59:08 by wkabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/*
#include "stdio.h"
int	main(void)
{
	char	str[50] = "Hello, World!";
	ft_bzero(str, 5);
	printf("After ft_bzero = %s\n", str);
	return (0);
}
*/