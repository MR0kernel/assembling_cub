/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strssize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrstein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:26:55 by chrstein          #+#    #+#             */
/*   Updated: 2024/06/27 12:27:02 by chrstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strssize(char **strs)
{
	size_t	size;

	if (!strs)
		return (0);
	size = 0;
	while (strs[size])
		size++;
	return (size);
}
