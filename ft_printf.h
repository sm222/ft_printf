/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 13:13:03 by anboisve          #+#    #+#             */
/*   Updated: 2022/11/10 09:14:55 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

int		ft_printf(const char *str, ...);
int		ft_put_p(uintptr_t nbr);
char	*ft_ulltoa(unsigned long long nb, int base);
int		ft_put_hex(unsigned int val, char maj);
int		ft_put_u(unsigned int nb);

#endif
