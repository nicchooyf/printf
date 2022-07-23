/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 19:10:35 by nchoo             #+#    #+#             */
/*   Updated: 2022/07/19 21:17:01 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_precision_str(f_pf *flag, int len)
{
	if (flag->dot)
	{
		if (!flag->precision)
			len = 0;
		else if (len > flag->precision)
			len = flag->precision;
	}
	flag->precision = 0;
	flag->dot = 0;
	return (len);
}

/*
 *	
 */
int	check_precision_int(f_pf *flag, int len, int nb)
{
	if (flag->dot)
	{
		if (flag->precision)
		{
			flag->zero = 1;
			if (flag->width > flag->precision && flag->precision >= len)
				flag->pad = flag->width - flag->precision;
			if (flag->precision >= len)
				flag->width = flag->precision;
		}
		else
			if (nb == 0)
				len = 0; 
	}
	return (len);
}

int	check_precision_uint(f_pf *flag, int len, unsigned int nb)
{
	if (flag->dot)
	{
		if (flag->precision)
		{
			flag->zero = 1;
			if (flag->width > flag->precision && flag->precision >= len)
				flag->pad = flag->width - flag->precision;
			if (flag->precision >= len)
				flag->width = flag->precision;
		}
		else
			if (nb == 0)
				len = 0;
	}
	return (len);
}