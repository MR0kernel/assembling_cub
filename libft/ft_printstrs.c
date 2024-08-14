/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstrs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrstein <chrstein@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 03:45:40 by chrstein          #+#    #+#             */
/*   Updated: 2024/06/27 04:25:34 by chrstein         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printstrs(char **strs, int fd)
{
	size_t	i;

	i = -1;
	if (!strs)
		ft_dprintf(fd, "(null)");
	while (strs && strs[++i])
		ft_dprintf(fd, "%s", strs[i]);
	ft_dprintf(1, "\n");
}
