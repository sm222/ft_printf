/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 09:51:56 by anboisve          #+#    #+#             */
/*   Updated: 2022/11/07 10:27:39 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_size_int(int nb)
{
	int long	tmp;
	int			size;

	tmp = nb;
	size = 1;
	if (tmp < 0)
	{
		tmp *= -1;
		size++;
	}
	while (tmp > 9)
	{
		tmp /= 10;
		size++;
	}
	return (size);
}
