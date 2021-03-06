/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 14:46:13 by nchoo             #+#    #+#             */
/*   Updated: 2022/07/17 21:32:29 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 *	Get print length to pass into width functions
 */
static void get_hex_length(t_ull point, f_pf *p)
{
    if (point >= 16)
    {
        get_hex_length(point / 16, p);
        get_hex_length(point % 16, p);
    }
    if (point < 16)
    {
        p->hexlen++;
    }
}

/*
 *	Very similar to the p flag
 */
void ft_printhex(f_pf *flag)
{
	unsigned int	lu;
	char			*base;
	
	lu = va_arg(flag->arg, unsigned long);
	if (flag->upper == 1)
		base = ft_strdup("ABCDEF");
	else
		base = ft_strdup("abcdef");
	get_hex_length(lu, flag);
	check_left(flag, flag->hexlen);
	flag->hexlen = check_precision_uint(flag, flag->hexlen, lu);
	check_zero(flag, flag->hexlen);
	if (lu)
		ft_putnbr_base(lu, flag, base);
	else if (!flag->dot || flag->precision > 0)
		flag->len += write(1, "0", 1);
	check_right(flag, flag->hexlen);
	free(base);
	flag->hexlen = 0;
}