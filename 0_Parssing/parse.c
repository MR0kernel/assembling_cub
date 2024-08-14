/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrstein <chrstein@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 03:47:15 by chrstein          #+#    #+#             */
/*   Updated: 2024/06/27 12:49:18 by chrstein         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_all_identifer(t_data *data)
{
	if (!data->ea_xpm || !data->no_xpm || !data->ea_xpm || !data->we_xpm)
	{
		ft_dprintf(2, "Error\nNeed all the identifiers before the map\n");
		return (free_all(data), exit(1));
	}
	if (data->c_blue == -1 || data->c_green == -1 || data->c_red == -1)
	{
		ft_dprintf(2, "Error\nNeed the ceiling colors\n");
		return (free_all(data), exit(1));
	}
	if (data->f_blue == -1 || data->f_green == -1 || data->f_red == -1)
	{
		ft_dprintf(2, "Error\nNeed the floor colors\n");
		return (free_all(data), exit(1));
	}
}

void	fill_map(t_data *data)
{
	char	*line_ptr;
	t_list	*new;

	line_ptr = data->line;
	while (*line_ptr == ' ')
		line_ptr++;
	if (*line_ptr != '1')
	{
		ft_dprintf(2, "Error\n%s : Incorrect line\n", data->line);
		return (free_all(data), exit(1));
	}
	check_all_identifer(data);
	while (data->line)
	{
		new = ft_lstnew(data->line);
		if (!new)
			return (free_all(data), exit(1));
		ft_lstadd_back(&data->lst_map, new);
		data->line = get_next_line(data->fd);
	}
	data->map = ft_lst_to_strs(data->lst_map);
	if (!data->map)
		return (free_all(data), exit(1));
}

void	fill_identifier(t_data *data)
{
	if (!ft_strncmp(data->line, "NO ", 3))
		xpm_load(data, &data->no_xpm);
	else if (!ft_strncmp(data->line, "SO ", 3))
		xpm_load(data, &data->so_xpm);
	else if (!ft_strncmp(data->line, "EA ", 3))
		xpm_load(data, &data->ea_xpm);
	else if (!ft_strncmp(data->line, "WE ", 3))
		xpm_load(data, &data->we_xpm);
	else if (!ft_strncmp(data->line, "F ", 2))
		fill_color(data, 'F');
	else if (!ft_strncmp(data->line, "C ", 2))
		fill_color(data, 'C');
	else if (*data->line != '\n')
	{
		fill_map(data);
	}
}

void	parse(t_data *data)
{
	data->line = get_next_line(data->fd);
	if (!data->line)
	{
		ft_dprintf(2, "Error\nEmpty file\n");
		return (free_all(data), exit(1));
	}
	while (data->line)
	{
		fill_identifier(data);
		free(data->line);
		data->line = get_next_line(data->fd);
	}
	check_map(data, data->map, 0);
}
