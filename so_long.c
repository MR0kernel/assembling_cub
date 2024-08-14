/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilrodr <guilrodr@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:04:26 by guilrodr          #+#    #+#             */
/*   Updated: 2023/12/10 13:22:37 by guilrodr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int number_of_args, char **args)
{
	t_master	master;

	init_master_struct(&master);
	if (perform_parssing(number_of_args, args, &master))
		basic_error_handler(&master, 1);
	init_map_size(&master);
	if (master.mlx == NULL)
		second_class_error_handler(&master, 10);
	launch_window(&master);
	fifth_class_error_handler(&master, 0);
	return (0);
}
