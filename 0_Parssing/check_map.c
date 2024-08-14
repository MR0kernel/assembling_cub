/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrstein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:50:08 by chrstein          #+#    #+#             */
/*   Updated: 2024/06/27 12:50:11 by chrstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_if_surround(t_data *data, char **map, int j, int i)
{
	if (!j || !i || !map[j + 1] || \
	is_void(map[j - 1][i]) || is_void(map[j + 1][i]) || \
	is_void(map[j][i - 1]) || is_void(map[j][i + 1]))
	{
		ft_dprintf(2, "Error\nThe map must be closed/surrounded by walls\n");
		return (free_all(data), exit(1));
	}
}

void	fill_player(t_data *data, char orientation, int j, int i)
{
	if (data->spawning_orientation)
	{
		ft_dprintf(2, "Error\nThe map must be composed by only one player\n");
		return (free_all(data), exit(1));
	}
	data->spawning_orientation = orientation;
	data->player_y = j;
	data->player_x = i;
	data->map[j][i] = '0';
}

void	check_map(t_data *data, char **map, int i)
{
	int	j;

	j = -1;
	while (map[++j])
	{
		i = -1;
		while (map[j][++i])
		{
			if (map[j][i] == '0' || is_player(map[j][i]))
				check_if_surround(data, map, j, i);
			else if (map[j][i] != '1' && map[j][i] != ' ' && map[j][i] != '\n')
			{
				ft_dprintf(2, ERRCHARM, map[j][i]);
				return (free_all(data), exit(1));
			}
			if (is_player(map[j][i]))
				fill_player(data, map[j][i], j, i);
		}
		if (map[j + 1] && map[j + 1][0] == '\n' \
				&& map_is_not_finished(map, j + 1))
		{
			ft_dprintf(2, ERREMPTYLINE);
			return (free_all(data), exit(1));
		}
	}
}
