/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:01:10 by anboisve          #+#    #+#             */
/*   Updated: 2022/11/10 09:14:55 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_u(unsigned int nb)
{
	int		size;
	char	*tmp;

	tmp = ft_ulltoa(nb, 10);
	size = ft_putstr_fd(tmp, STDOUT_FILENO);
	ft_safe_free(tmp);
	return (size);
}
