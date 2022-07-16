/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:52:50 by nchoo             #+#    #+#             */
/*   Updated: 2022/07/16 23:11:06 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 *	Checks left or right allignment
 */
void	check_left(f_pf *flag, int len)
{
	if (!flag->left && flag->width)
		ft_pad_space(flag, len);
	else
		return ;
}

void	check_right(f_pf *flag, int len)
{
	if (flag->left && flag->width)
		ft_pad_space(flag, len);
	else
		return ;
}

/*
 *	Pads with spaces up to specified width
 *  len - length of printed type
 * 
 *	If len > width, no padding
 */
void ft_pad_space(f_pf *flag, int len)
{
	if (flag->width > len)
	{
		flag->width -= len;
		while (flag->width > 0)
		{
			flag->len += write(1, " ", 1);
			flag->width--;
		}
	}
	flag->width = 0;
}

void ft_pad_zero(f_pf *flag, int len)
{
	if ()
}
