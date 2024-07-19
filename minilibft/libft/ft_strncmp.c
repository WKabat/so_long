/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkabat <wkabat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:50:29 by wkabat            #+#    #+#             */
/*   Updated: 2024/03/15 10:34:17 by wkabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] != 0 || s2[i] != 0) && i < n)
	{
		if (s1[i] != s2[i] && n > i)
			return (((unsigned char *) s1)[i] - ((unsigned char *) s2)[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
int	main()
{
	//char	s1[3] = "abc";
	//char	s2[4] = "abcd";
	//int	n;
	
	//n = 5;
	printf("%d\n", ft_strncmp("zyxbcdefgh", "abcdwxyz", 0));
	printf("%d\n", strncmp("zyxbcdefgh", "abcdwxyz", 0));
	return (0);
}
*/