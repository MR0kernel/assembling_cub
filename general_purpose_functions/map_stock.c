/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_stock.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilrodr <guilrodr@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 20:28:51 by guilrodr          #+#    #+#             */
/*   Updated: 2023/12/10 13:52:32 by guilrodr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	place_values(t_master *master, int y_index, int x_index);

void	init_map_size(t_master *master)
{
	char	**map;
	int		y_index;
	int		x_index;
	int		size_x;

	map = master->map.original_map;
	y_index = 0;
	x_index = 0;
	while (map[y_index])
	{
		size_x = ft_strlen(map[y_index]);
		if (size_x > x_index)
			x_index = size_x;
		y_index++;
	}
	place_values(master, y_index, x_index);
}

void	place_values(t_master *master, int y_index, int x_index)
{
	master->map.map_size_y = y_index;
	master->map.map_size_x = x_index - 1;
}
