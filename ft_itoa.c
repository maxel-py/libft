/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftragula <ftragula@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 21:58:07 by ftragula          #+#    #+#             */
/*   Updated: 2021/10/10 14:18:03 by ftragula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sign_len(int nbr)
{
	int	len;

	if (nbr <= 0)
		len = 1;
	else
		len = 0;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	unsigned int	nbr;
	int				len;
	char			*final;

	if (n < 0)
		nbr = -n;
	else
		nbr = n;
	len = ft_sign_len(n);
	final = malloc(sizeof(char) * len + 1);
	if (!final)
		return (NULL);
	final[len--] = '\0';
	while (len >= 0)
	{
		final[len--] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (n < 0)
		final[0] = '-';
	return (final);
}
