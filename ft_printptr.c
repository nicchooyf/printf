/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 22:41:44 by nchoo             #+#    #+#             */
/*   Updated: 2022/07/16 12:58:22 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

typedef unsigned long long	t_ull;

/*
 *	recursive, like ft_putnbr but in base 16
 */
static void	ft_putptr(t_ull point, f_pf *flag, char *base)
{
	if (point >= 16)
	{
		ft_putptr(point / 16, flag, base);
		ft_putptr(point % 16, flag, base);
	}
	else if (point < 16)
	{
		if (point < 10)
		{
			point += '0';
			write(1, &point, 1);
		}
		else
			write(1, &base[point - 10], 1);
		flag->len++;
	}
}

/*
 *	pass hexadecimal base to ft_putptr
 *	if point != 0
 *		execute ft_putptr function
 *	else
 *		write (nil)
 */
void	ft_printptr(f_pf *flag)
{
	t_ull	point;
	char	*p;

	p = ft_strdup("abcdef");
	point = va_arg(flag->arg, t_ull);
	if (point)
	{
		flag->len += write(1, "0x", 2);
		ft_putptr(point, flag, p);
	}
	else
		flag->len += write(1, "(nil)", 5);
	free(p);
}
