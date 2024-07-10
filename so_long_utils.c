/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkabat <wkabat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:22:03 by wkabat            #+#    #+#             */
/*   Updated: 2024/07/10 12:51:33 by wkabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_space(t_map_check *map)
{
	int	i;

	i = 0;
	if (map->buff != NULL)
	{
		free (map -> buff);
		map -> buff = NULL;
	}
	if (map->map != NULL)
	{
		while (map->map[i])
			free(map->map[i++]);
		free(map->map);
		map -> map = NULL;
	}
}