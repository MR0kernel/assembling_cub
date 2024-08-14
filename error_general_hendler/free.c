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

void	free_all(t_data *data)
{
	free(data->line);
	free(data->map);
	ft_lstclear(&data->lst_map, &free);
	if (data->no_xpm)
		mlx_destroy_image(data->mlx, data->no_xpm);
	if (data->so_xpm)
		mlx_destroy_image(data->mlx, data->so_xpm);
	if (data->ea_xpm)
		mlx_destroy_image(data->mlx, data->ea_xpm);
	if (data->we_xpm)
		mlx_destroy_image(data->mlx, data->we_xpm);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	if (data->fd != -1)
		close(data->fd);
	free(data->mlx);
}
