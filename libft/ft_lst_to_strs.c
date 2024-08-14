/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_to_strs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrstein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:28:49 by chrstein          #+#    #+#             */
/*   Updated: 2024/06/27 12:28:58 by chrstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_lst_to_strs(t_list *lst)
{
	char	**strs;
	size_t	i;

	strs = ft_calloc(ft_lstsize(lst) + 1, sizeof(char *));
	if (!strs)
		return (NULL);
	i = 0;
	while (lst)
	{
		strs[i++] = lst->content;
		lst = lst->next;
	}
	return (strs);
}
