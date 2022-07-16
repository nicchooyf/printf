/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 14:46:13 by nchoo             #+#    #+#             */
/*   Updated: 2022/07/16 15:22:37 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_base_x(unsigned int point, f_pf *flag, char *base)
{
	if (point >= 16)
	{
		ft_putnbr_base_x(point / 16, flag, base);
		ft_putnbr_base_x(point % 16, flag, base);
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
 *	24, 25, 27, 28, 29
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
	ft_putnbr_base_x(lu, flag, base);
	free(base);
}