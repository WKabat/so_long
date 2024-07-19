/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkabat <wkabat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:59:27 by wkabat            #+#    #+#             */
/*   Updated: 2024/03/15 10:39:55 by wkabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	token_counter(char const *s, char d)
{
	size_t	tokens;
	int		in_token;

	tokens = 0;
	while (*s)
	{
		in_token = 0;
		if (*s == d && *s)
			s++;
		while (*s != d && *s)
		{
			if (in_token == 0)
			{
				in_token = 1;
				tokens++;
			}
			s++;
		}
	}
	return (tokens);
}

static int	safe_malloc(char **tokenv, int p, size_t buffer)
{
	int	i;

	i = 0;
	tokenv[p] = malloc(buffer);
	if (tokenv[p] == NULL)
	{
		while (i < p)
		{
			free (tokenv[i]);
			i++;
		}
		free (tokenv);
		return (1);
	}
	return (0);
}

static int	fill_words(char **tokenv, char const *s, char d)
{
	size_t	len;
	int		i;

	i = 0;
	while (*s)
	{
		len = 0;
		while (*s == d && *s)
			s++;
		while (*s != d && *s)
		{
			len++;
			s++;
		}
		if (len)
		{
			if (safe_malloc(tokenv, i, len + 1))
				return (1);
			ft_strlcpy (tokenv[i], s - len, len + 1);
			i++;
		}
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	size_t	tokens;
	char	**tokenv;

	if (s == 0)
		return (NULL);
	tokens = 0;
	tokens = token_counter(s, c);
	tokenv = malloc((tokens + 1) * sizeof(char *));
	if (tokenv == 0)
		return (NULL);
	tokenv[tokens] = NULL;
	if (fill_words(tokenv, s, c))
		return (NULL);
	return (tokenv);
}
/*
#include <stdio.h>
int	main()
{
	char	*str = "Hello World! 42 School!";
	char	**v = ft_split(str, ' ');

	while (*v)
	{
		printf("%s\n", *v);
		v++;
	}
	return (0);
}
*/