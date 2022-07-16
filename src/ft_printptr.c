/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 22:41:44 by nchoo             #+#    #+#             */
/*   Updated: 2022/07/16 14:54:51 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	char	*base;

	base = ft_strdup("abcdef");
	point = va_arg(flag->arg, t_ull);
	if (point)
	{
		flag->len += write(1, "0x", 2);
		ft_putnbr_base(point, flag, base);
	}
	else
		flag->len += write(1, "(nil)", 5);
	free(base);
}
