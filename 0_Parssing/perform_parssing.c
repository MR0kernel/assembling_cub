/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrstein <chrstein@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 03:46:35 by chrstein          #+#    #+#             */
/*   Updated: 2024/06/27 11:56:01 by chrstein         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void confert_parssing(t_data *data, t_master *master);

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
	if (data->mlx_win)
		mlx_destroy_window(data->mlx, data->mlx_win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	if (data->fd != -1)
		close(data->fd);
	free(data->mlx);
}

void	set_data(t_data *data, char *path)
{
	data->mlx = NULL;
	data->mlx_win = NULL;
	ft_bzero((char *)data, sizeof(t_data));
	data->fd = open(path, __O_DIRECTORY);
	if (data->fd != -1)
	{
		ft_dprintf(2, "Error\n%s: is a directory\n", path);
		return (free_all(data), exit(1));
	}
	data->fd = open(path, O_RDONLY);
	if (data->fd == -1)
	{
		ft_dprintf(2, "Error\n%s: %s\n", path, strerror(errno));
		return (free_all(data), exit(1));
	}
	data->c_blue = -1;
	data->c_red = -1;
	data->c_green = -1;
	data->f_blue = -1;
	data->f_red = -1;
	data->f_green = -1;
}

int	destroy(t_data *data)
{
	return (free_all(data), exit(0), 0);
}

// int	key_press(int key_code, t_data *data)
// {
// 	if (key_code == ESC)
// 		return (destroy(data));
// 	else if (key_code == A)
// 		move(&data, data, data.player_x - 1, data.player_y);
// 	else if (key_code == D)
// 		move(&data, data, data.player_x + 1, data.player_y);
// 	else if (key_code == S)
// 		move(&data, data, data.player_x, data.player_y + 1);
// 	else if (key_code == W)
// 		move(&data, data, data.player_x, data.player_y - 1);
// 	return (1);
// }

void	print_debug(t_data *data)
{
	ft_dprintf(2, "\nC_red %d\nC_green %d\nC_blue %d\n\nF_red %d\nF_green %d\nF_blue %d\n\nP_x %d\nP_y %d\norientation %c\n\n", \
	data->c_red, data->c_green, data->c_blue, data->f_red, data->f_green, data->f_blue, \
	data->player_x, data->player_y, data->spawning_orientation);
	ft_printstrs(data->map, 2);
}

int	perform_parssing(int argc, char **argv, t_master *master)
{
	t_data	data;

	if (argc != 2 || ft_strlen(argv[1]) < 5 || \
	!ft_rstrnstr(argv[1], ".cub", 4))
		return (ft_dprintf(2, "Error\narg not valide\n"), 1);
	set_data(&data, argv[1]);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (free_all(&data), 1);
	parse(&data);
	confert_parssing(&data, master);
	print_debug(&data);
	return(0);
}

static void confert_parssing(t_data *data, t_master *master)
{
	master->map.original_map = data->map;
	master->map.ceiling_color = data->ceiling_color;
	master->map.floor_color = data->floor_color;
	master->player.x = data->player_x;
	master->player.y = data->player_y;
	// faire la fontion pour spawn orientation
	master->imgs.exit_img = data->no_xpm;
	master->imgs.floor_img = data->so_xpm;
	master->imgs.player_img = data->ea_xpm;
	master->imgs.wall_img = data->we_xpm;
	master->mlx = data->mlx;

}
// free_all(&data);
