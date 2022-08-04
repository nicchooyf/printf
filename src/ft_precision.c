/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 19:10:35 by nchoo             #+#    #+#             */
/*   Updated: 2022/08/05 03:15:04 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 *	
 */
int	check_precision_int(f_pf *flag, int len, int nb)
{
	if (flag->dot)
	{
		if (flag->precision)
		{
			if (flag->precision > len)
				flag->zero = 1;
			else
				flag->zero = 0;
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
			if (flag->precision > len)
				flag->zero = 1;
			else
				flag->zero = 0;
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