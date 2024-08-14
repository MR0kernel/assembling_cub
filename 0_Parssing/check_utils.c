/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrstein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:50:14 by chrstein          #+#    #+#             */
/*   Updated: 2024/06/27 12:50:16 by chrstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	is_player(char c)
{
	if (c == 'N' || c == 'E' || c == 'W' || c == 'S')
		return (true);
	return (false);
}

bool	is_void(char c)
{
	if (c == '1' || c == '0' || is_player(c))
		return (false);
	return (true);
}

bool	map_is_not_finished(char **map, int j)
{
	int	j_cpy;

	j_cpy = j;
	while (map[j] && map[j][0] == '\n')
		j++;
	if (map[j])
		return (true);
	map[j_cpy] = NULL;
	return (false);
}
