/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftragula <ftragula@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 18:44:42 by ftragula          #+#    #+#             */
/*   Updated: 2021/10/06 18:44:42 by ftragula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (dst[i] != '\0' && i < dstsize)
		i++;
	len = i;
	while (src[i - len] != '\0' && i + 1 < dstsize)
	{
		dst[i] = src[i - len];
		i++;
	}
	if (i < dstsize)
		dst[i] = '\0';
	return (len + ft_strlen(src));
}
