/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkabat <wkabat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:57:20 by wkabat            #+#    #+#             */
/*   Updated: 2024/03/20 11:54:08 by wkabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_nmblen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*ft_nbrmin(int n, int len)
{
	char	*str;

	if (n == -2147483648)
	{
		str = ft_strdup ("-2147483648");
		return (str);
	}
	else
	{
		str = (char *)malloc(sizeof(char) * (len + 1));
		if (str == NULL)
			return (NULL);
		str[0] = '-';
		n = -n;
	}
	str[len] = '\0';
	while (len > 1)
	{
		str[len - 1] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = ft_nmblen(n);
	if (n < 0)
	{
		str = ft_nbrmin(n, len);
		return (str);
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	while (len > 0)
	{
		str[len - 1] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (str);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	int	x;
	int	y;
	int	z;
	char	*str1;
	char	*str2;
	char	*str3;

	str1 = ft_itoa(42);
	str2 = ft_itoa(215600);
	str3 = ft_itoa(-2147483648);
	x = -42;
	y = 215600;
	z = -2147483648;
	printf("%s\n%s\n%s\n", (str1), (str2), (str3));
	free(str1);
	free(str2);
	free(str3);
	return (0);
}
*/