/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrstein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:50:39 by chrstein          #+#    #+#             */
/*   Updated: 2024/06/27 12:50:40 by chrstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_xpm(t_data *data, char *line_ptr)
{
	int	fd;

	if (*line_ptr == '\0' || *line_ptr == '\n')
	{
		ft_dprintf(2, "Error\nNothing after %s\n", data->line);
		return (free_all(data), exit(1));
	}
	if (!ft_rstrnstr(line_ptr, ".xpm\n", 5))
	{
		ft_dprintf(1, "Error\nNeed a .xpm file : %s\n", data->line);
		return (free_all(data), exit(1));
	}
	fd = ft_strlen(line_ptr) - 1;
	line_ptr[fd] = '\0';
	fd = open(line_ptr, O_RDONLY);
	if (fd == -1)
	{
		ft_dprintf(2, "Error\n%s : %s\n", line_ptr, strerror(errno));
		return (free_all(data), exit(1));
	}
	close(fd);
}

void	xpm_load(t_data *data, void **xpm_ptr)
{
	char	*line_ptr;
	int		width;
	int		height;

	if (*xpm_ptr)
	{
		ft_dprintf(2, "Error\nMultiple indentifier %c%c found\n", \
		*data->line, data->line[1]);
		return (free_all(data), exit(1));
	}
	line_ptr = data->line + 3;
	while (*line_ptr == ' ')
		line_ptr++;
	check_xpm(data, line_ptr);
	*xpm_ptr = mlx_xpm_file_to_image(data->mlx, line_ptr, &width, &height);
	if (*xpm_ptr == NULL)
	{
		ft_dprintf(2, "Error\nCan't load %s\n", line_ptr);
		return (free_all(data), exit(1));
	}
}
