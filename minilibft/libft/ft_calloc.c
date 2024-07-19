/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkabat <wkabat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:37:34 by wkabat            #+#    #+#             */
/*   Updated: 2024/03/15 10:52:03 by wkabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	max_val;
	void	*ptr;

	max_val = -1;
	if (nmemb != 0 && max_val / nmemb < size)
		return (NULL);
	ptr = (void *)malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

/*
#include "stdio.h"
int	main(void)
{
	int	n;
	int	*ptr;
	int	i;

	n = 7;
	i = 0;
	ptr = (int *)ft_calloc(n, 5);
	while (i < n )
	{
		printf("%d ", ptr[i]);
		i++;
	}
	printf("\n");
	free (ptr);
	return (0);
}
*/
