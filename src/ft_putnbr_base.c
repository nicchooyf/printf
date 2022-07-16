/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 14:41:23 by nchoo             #+#    #+#             */
/*   Updated: 2022/07/16 14:59:29 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 *	recursive, like C04 ft_putnbr but in base 16
 */
void	ft_putnbr_base(t_ull point, f_pf *flag, char *base)
{
	if (point >= 16)
	{
		ft_putnbr_base(point / 16, flag, base);
		ft_putnbr_base(point % 16, flag, base);
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