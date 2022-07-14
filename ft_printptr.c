/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 22:41:44 by nchoo             #+#    #+#             */
/*   Updated: 2022/07/14 23:27:07 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

typedef unsigned long long ull;

static void ft_putptr(ull point, f_pf *flag)
{
	char base[] = {"abcdef"};
	
	if (point >= 16)
	{
		ft_putptr(point / 16, flag);
		ft_putptr(point % 16, flag);
	}
	else if (point < 16)
	{
		if (point < 10)
		{
			point += '0';
			write(1 ,&point, 1);
		}
		else
			write(1, &base[point - 10], 1);
		flag->len++;
	}
}

void ft_printptr(f_pf *flag)
{
	ull point;
	
	point = va_arg(flag->arg, ull);
	if (point)
	{
		flag->len += write(1, "0x", 2);
		ft_putptr(point, flag);
	}
}



