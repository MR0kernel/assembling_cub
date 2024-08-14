/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_white_space.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrstein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:23:59 by chrstein          #+#    #+#             */
/*   Updated: 2024/06/27 12:24:06 by chrstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_replace_white_space(char *line)
{
	while (*line)
	{
		if (ft_iswhitespace(*line))
			*line = ' ';
		line++;
	}
}
