/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkabat <wkabat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 10:06:47 by wkabat            #+#    #+#             */
/*   Updated: 2024/03/15 10:59:43 by wkabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	number;
	int	minus;

	number = 0;
	minus = 1;
	while ((*nptr >= 9 && *nptr <= 13) || (*nptr == 32))
	{
		nptr++;
	}
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			minus *= -1;
		++nptr;
	}
	while (*nptr >= 48 && *nptr <= 57)
	{
		number *= 10;
		number += *nptr - 48;
		nptr++;
	}
	return (number * minus);
}
/*
#include <stdio.h>
int	main(void)
{
	char	str[] = "    -1234s567";
	
	printf("%d\n", ft_atoi(str));
	printf("%d\n", atoi(str));
	return (0);
}
*/