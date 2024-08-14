/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilrodr <guilrodr@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 21:19:37 by guilrodr          #+#    #+#             */
/*   Updated: 2023/12/09 18:18:47 by guilrodr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_map(char **map, size_t y_index)
{
	size_t	index;

	index = 0;
	while (index < y_index)
	{
		free(map[index]);
		index++;
	}
	free(map);
}
