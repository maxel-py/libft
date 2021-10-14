/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maksimelistratov <maksimelistratov@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 18:50:14 by ftragula          #+#    #+#             */
/*   Updated: 2021/10/14 11:19:03 by maksimelist      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*out;
	unsigned int	i;

	i = 0;
	if (f && s)
	{
		out = (char *)malloc(sizeof(char)*ft_strlen(s)+1);
		if (!out)
			return (NULL);
		while (s[i] != '\0')
		{
			out[i] = f(i, s[i]);
			i++;
		}
		out[i] = '\0';
		return (out);
	}
	return (NULL);
}
