/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_and_null.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrstein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:21:49 by chrstein          #+#    #+#             */
/*   Updated: 2024/06/27 12:22:11 by chrstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_and_null(void *ptr_adrs)
{
	void	**tmp;

	if (ptr_adrs)
	{
		tmp = (void **)ptr_adrs;
		if (*tmp)
		{
			free(*tmp);
			*tmp = NULL;
		}
	}
}
