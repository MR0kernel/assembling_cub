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

static void	confert_parssing(t_data *data, t_master *master);

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

void	print_debug(t_data *data)
{
	ft_dprintf(2, "\nC_red %d\nC_green %d\nC_blue \
			%d\n\nF_red %d\nF_green %d\nF_blue %d\n\nP_x \
			%d\nP_y %d\norientation %c\n\n", \
	data->c_red, data->c_green, data->c_blue, \
			data->f_red, data->f_green, data->f_blue, \
	data->player_x, data->player_y, data->spawning_orientation);
	ft_printstrs(data->map, 2);
}

int	perform_parssing(int argc, char **argv, t_master *master)
{
	t_data	data;

	if (argc != 2 || ft_strlen(argv[1]) < 5 || \
	!ft_rstrnstr(argv[1], ".cub", 4))
	{
		ft_dprintf(2, "Error\narg not valide\n");
		exit(1);
	}
	set_data(&data, argv[1]);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (free_all(&data), 1);
	parse(&data);
	confert_parssing(&data, master);
	if (data.fd != -1)
		close(data.fd);
	return (0);
}

static void	confert_parssing(t_data *data, t_master *master)
{
	master->map.original_map = data->map;
	master->map.ceiling_color = data->ceiling_color;
	master->map.floor_color = data->floor_color;
	master->player.x = ((double)data->player_x + 0.5);
	master->player.y = ((double)data->player_y + 0.5);
	master->imgs.exit_img = data->no_xpm;
	master->imgs.floor_img = data->so_xpm;
	master->imgs.player_img = data->ea_xpm;
	master->imgs.wall_img = data->we_xpm;
	master->mlx = data->mlx;
	if (data->spawning_orientation == 'N')
		master->player.dir = 4.71238898;
	else if (data->spawning_orientation == 'S')
		master->player.dir = 1.570796327;
	else if (data->spawning_orientation == 'E')
		master->player.dir = 0;
	else
		master->player.dir = 3.141592653;
	master->data = data;
	master->lst_map = data->lst_map;
}
