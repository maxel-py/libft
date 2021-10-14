/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftragula <ftragula@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 18:52:12 by ftragula          #+#    #+#             */
/*   Updated: 2021/10/06 18:52:38 by ftragula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *string1, const char *string2, size_t num)
{
	while ((*string1 || *string2) && num--)
		if (*string1++ != *string2++)
			return ((unsigned char)*--string1 - (unsigned char)*--string2);
	return (0);
}
