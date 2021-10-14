/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftragula <ftragula@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 18:26:57 by ftragula          #+#    #+#             */
/*   Updated: 2021/10/10 15:12:36 by ftragula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(char c, char const *str)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

static char	*ft_try_malloc(char const *s, size_t begin, size_t end, size_t i)
{
	char	*str;

	str = (char *)malloc(sizeof(*s) * (end - begin + 1));
	if (!str)
		return (NULL);
	while (begin < end)
		str[i++] = s[begin++];
	str[i] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	begin;
	size_t	end;
	char	*str;

	i = 0;
	if (!s1)
		return (NULL);
	while (s1[i] && ft_check(s1[i], set) == 1)
		i++;
	begin = i;
	while (s1[i] != '\0')
		i++;
	while (ft_check(s1[i - 1], set) == 1)
		i--;
	end = i;
	if (begin > end)
		begin = end;
	i = 0;
	str = ft_try_malloc(s1, begin, end, i);
	return (str);
}
