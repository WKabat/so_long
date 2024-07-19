/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkabat <wkabat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:39:05 by wkabat            #+#    #+#             */
/*   Updated: 2024/03/04 13:25:46 by wkabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *) s;
	while (i < n)
	{
		if ((unsigned char) str[i] == (unsigned char) c)
			return ((char *) s + i);
		i++;
	}
	return (NULL);
}
/*
int	main()
{
	char	str[] = "Hello World!";
	int	c = 'k';

	printf("%p\n", ft_memchr(str, c, 7));
	return (0);	
}
*/
/*
The memchr() function scans the initial n bytes of the memory
area pointed to by s for the first instance of c.  Both c and the
bytes of the memory area pointed to by s are interpreted as
unsigned char.
The memchr() and memrchr() functions return a pointer to the
matching byte or NULL if the character does not occur in the
given memory area.
*/