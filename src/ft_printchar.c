/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 02:04:13 by nchoo             #+#    #+#             */
/*   Updated: 2022/07/16 18:39:21 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 *	Simple write function to print char
 */
int ft_printchar(f_pf *flag)
{
	int	c;
	c = va_arg(flag->arg, int);
	if (!flag->left && flag->width)
		ft_pad_width(flag, 1);
	write(1, &c, 1);
	if (flag->left && flag->width)
		ft_pad_width(flag, 1);
	return (1);
}