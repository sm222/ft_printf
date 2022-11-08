/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:09:21 by anboisve          #+#    #+#             */
/*   Updated: 2022/11/08 14:58:20 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_p(uintptr_t p)
{
	char	*v_p;
	int		size;

	ft_putstr_fd("0x", STDOUT_FILENO);
	v_p = ft_utob((unsigned long int)p, 16);
	size = ft_putstr_fd(v_p, STDOUT_FILENO);
	if (v_p)
		free(v_p);
	return (size + 2);
}
