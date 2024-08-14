/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_general_hendler.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilrodr <guilrodr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 20:41:19 by guilrodr          #+#    #+#             */
/*   Updated: 2024/08/13 20:50:30 by guilrodr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	basic_error_handler(t_master *master, int error_code)
{
	if (error_code == 1)
		ft_dprintf(2, "Wrong number of arguments only a map must be given\n");
	else if (error_code == 2)
		ft_dprintf(2, "given map is invalid, must be a .ber map\n");
	else if (error_code == 3)
		ft_dprintf(2, "can't open given map, no \
				rights or file does not exist\n");
	else if (error_code == 4)
		ft_dprintf(2, "fail getting map, maybe empty file ? \n");
	else if (error_code == 5)
		ft_dprintf(2, "map is not rectangular\n");
	else if (error_code == 6)
	{
		ft_dprintf(2, "malloc failed xD\n");
		if (master)
			free(master);
		exit(EXIT_FAILURE);
	}
	ft_lstclear(&master->lst_map, &free);
	exit(EXIT_FAILURE);
}

void	second_class_error_handler(t_master *master, int error_code)
{
	if (error_code == 1)
		ft_dprintf(2, "Map must be closed\n");
	else if (error_code == 2)
		ft_dprintf(2, "Map must only contain P,C,E,0 and 1\n");
	else if (error_code == 3)
		ft_dprintf(2, "Game must only contain one player \n");
	else if (error_code == 4)
		ft_dprintf(2, "Game must only contain one exit\n");
	else if (error_code == 5)
		ft_dprintf(2, "Game must contain at least one collectible\n");
	else if (error_code == 6)
		ft_dprintf(2, "Player must be able to win\n");
	else if (error_code == 7)
		ft_dprintf(2, "Not all collectibles are reacheble\n");
	else if (error_code == 8)
		ft_dprintf(2, "Exit is not reacheble\n");
	else if (error_code == 9)
		ft_dprintf(2, "t Einstein removed one of the images\n");
	else if (error_code == 10)
		ft_dprintf(2, "mlx failled to init\n");
	free(master->map.original_map);
	basic_error_handler(master, 0);
}

void	third_class_error_handler(t_master *master, int error_code)
{
	if (error_code == 1)
		ft_dprintf(2, "window failled to init\n");
	else if (error_code == 2)
		ft_dprintf(2, "");
	free_images(master);
	mlx_destroy_display(master->mlx);
	free(master->mlx);
	second_class_error_handler(master, 0);
}

void	fourth_class_error_handler(t_master *master, int error_code)
{
	if (error_code == 1)
		ft_dprintf(2, "could nor get wall image\n");
	else if (error_code == 2)
		ft_dprintf(2, "could nor get floor image\n");
	else if (error_code == 3)
		ft_dprintf(2, "could nor get collectible image\n");
	else if (error_code == 4)
		ft_dprintf(2, "could nor get exit image\n");
	else if (error_code == 5)
		ft_dprintf(2, "could nor get player image\n");
	third_class_error_handler(master, 0);
}

void	fifth_class_error_handler(t_master *master, int error_code)
{
	if (error_code == 1)
		ft_dprintf(2, "\n");
	else if (error_code == 2)
		ft_dprintf(2, "\n");
	else if (error_code == 3)
		ft_dprintf(2, "\n");
	else if (error_code == 4)
		ft_dprintf(2, "\n");
	else if (error_code == 5)
		ft_dprintf(2, "\n");
	mlx_destroy_window(master->mlx, master->win);
	fourth_class_error_handler(master, 0);
}
