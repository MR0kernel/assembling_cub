/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_window_master.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilrodr <guilrodr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 19:08:01 by guilrodr          #+#    #+#             */
/*   Updated: 2024/08/13 22:43:53 by guilrodr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	end_of_program_macro(t_master *master);
int	draw_player(t_master *master);

void	launch_window(t_master *master)
{
	master->win = mlx_new_window(master->mlx, SCREEN_SIZE_X, \
			SCREEN_SIZE_Y, "so_long_3D");
	if (!master->win)
		third_class_error_handler(master, 1);
	master->canvas = mlx_new_image(master->mlx, SCREEN_SIZE_X, SCREEN_SIZE_Y);
	mlx_loop_hook(master->mlx, draw_map, master);
	mlx_hook(master->win, 2, (1L << 1), keypress, master);
	mlx_hook(master->win, 17, 0, end_of_program_macro, master);
	mlx_hook(master->win, 3, (1L << 0), keyrelease, master);
	mlx_loop(master->mlx);
}

int	end_of_program_macro(t_master *master)
{
	end_of_program(master, 0);
	return (0);
}
