/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:52:50 by nchoo             #+#    #+#             */
/*   Updated: 2022/07/16 18:49:14 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 *	Pads with spaces up to specified width
 *  len - length of printed type
 * 
 *	If len > width, no padding
 */
void ft_pad_width(f_pf *flag, int len)
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
