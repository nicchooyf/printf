/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 22:41:44 by nchoo             #+#    #+#             */
/*   Updated: 2022/07/17 19:27:49 by nchoo            ###   ########.fr       */
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
 *	Pass hexadecimal base to ft_putnbr_base
 *	If point != 0
 *		Execute ft_putnbr_base
 *	Else
 *		Print(nil)
 */
void	ft_printptr(f_pf *flag)
{
	t_ull	point;
	
	point = va_arg(flag->arg, t_ull);
	if (point)
	{
		get_hex_length(point, flag);
		check_left(flag, flag->hexlen + 2);
		flag->len += write(1, "0x", 2);
		ft_putnbr_base(point, flag, "abcdef");
		check_right(flag, flag->hexlen + 2);
		flag->hexlen = 0;
	}
	else
	{
		check_left(flag, 5);
		flag->len += write(1, "(nil)", 5);
	}
}
