/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdelspace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrstein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:25:41 by chrstein          #+#    #+#             */
/*   Updated: 2024/06/27 12:28:40 by chrstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_whitespace(char *str)
{
	size_t	n;

	n = 0;
	while (*str)
		if (ft_iswhitespace(*str++))
			n++;
	return (n);
}

char	*ft_strdelspace(char *src)
{
	char	*dst;
	size_t	len;
	size_t	i;

	len = ft_strlen(src) - count_whitespace(src);
	dst = ft_calloc(len + 1, 1);
	if (!dst)
		return (NULL);
	i = 0;
	while (i < len)
		if (!ft_iswhitespace(*src++))
			dst[i++] = *(src - 1);
	return (dst);
}
