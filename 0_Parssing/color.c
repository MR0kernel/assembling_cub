/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrstein <chrstein@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:50:20 by chrstein          #+#    #+#             */
/*   Updated: 2024/06/27 14:26:56 by chrstein         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_color(t_data *data, char *line_ptr)
{
	size_t	i;
	int		nb_of_color;

	nb_of_color = 0;
	i = -1;
	while (line_ptr[++i] && line_ptr[i] != '\n')
	{
		if (ft_isdigit(line_ptr[i]))
		{
			nb_of_color++;
			while (ft_isdigit(line_ptr[i]))
				i++;
		}
		if (!ft_isdigit(line_ptr[i]) && line_ptr[i] != ',' && \
		line_ptr[i] != '\n' && line_ptr[i] != ' ')
		{
			ft_dprintf(2, ERRCHARC, *data->line, line_ptr[i]);
			return (free_all(data), exit(1));
		}
	}
	if (nb_of_color != 3)
	{
		ft_dprintf(2, "Error\nNeed R,G,B and R,G,B only !\n");
		return (free_all(data), exit(1));
	}
}

int	special_atoi(t_data *data, char **line_ptr)
{
	int		res;
	char	*ptr;

	ptr = *line_ptr;
	while (*ptr == ' ')
		ptr++;
	res = 0;
	while (*ptr && *ptr != ',' && *ptr != '\n')
	{
		res = res * 10 + (*ptr - 48);
		if (res > 255)
		{
			ft_dprintf(2, "Error\nR,G,B need value <= 255\n");
			free_all(data);
			exit(1);
		}
		ptr++;
	}
	while (*ptr == ',')
		ptr++;
	*line_ptr = ptr;
	return (res);
}

void	double_check_color(t_data *data, char color)
{
	if (color == 'C' && data->c_blue != -1)
	{
		ft_dprintf(2, "Error\nMultiple identifier %c\n", color);
		return (free_all(data), exit(1));
	}
	if (color == 'F' && data->f_blue != -1)
	{
		ft_dprintf(2, "Error\nMultiple identifier %c\n", color);
		return (free_all(data), exit(1));
	}
}

void	color_final(t_data *data, char color)
{
	if (color == 'F')
		data->floor_color = \
		(data->f_red << 16) | (data->f_green << 8) | data->f_blue;
	else
		data->ceiling_color = \
		(data->c_red << 16) | (data->c_green << 8) | data->c_blue;
}

void	fill_color(t_data *data, char color)
{
	char	*line_ptr;

	line_ptr = data->line + 2;
	while (*line_ptr == ' ')
		line_ptr++;
	if (*line_ptr == '\n' || *line_ptr == '\0')
	{
		ft_dprintf(2, "Error\nNothing after %s\n", data->line);
		return (free_all(data), exit(1));
	}
	check_color(data, line_ptr);
	double_check_color(data, color);
	if (color == 'C')
		data->c_red = special_atoi(data, &line_ptr);
	else
		data->f_red = special_atoi(data, &line_ptr);
	if (color == 'C')
		data->c_green = special_atoi(data, &line_ptr);
	else
		data->f_green = special_atoi(data, &line_ptr);
	if (color == 'C')
		data->c_blue = special_atoi(data, &line_ptr);
	else
		data->f_blue = special_atoi(data, &line_ptr);
	color_final(data, color);
}
