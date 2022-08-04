/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 14:29:55 by nchoo             #+#    #+#             */
/*   Updated: 2022/08/05 02:37:14 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 *	SAMPLE CASE
 *
 *	nb = 123
 *	tmp = 123
 *	while (tmp / 10)
 *		123 / 10 = 12
 *		12 / 10 = 1
 *		1 / 10 = 0
 *	div = 1000 
 *	while (1000 / 10)
 *		tmp = 123 / 100 = 1 + '0'
 *		write '1'
 *		nb %= div = 23;
 *	while (100 / 10)
 *		tmp = 23 / 10 = 2 + '0'
 *		write '2'
 *		nb %= div = 3
 *	while (10 /10)
 *		tmp = 3 / 1 = 3 + '0'
 *		write '3'
 *		nb %= div = 0
 */
void	ft_putnbr(f_pf *flag, size_t nb)
{
	size_t	tmp;
	size_t	div;

	div = 1;
	tmp = nb;
	while (tmp)
	{
		tmp /= 10;
		div *= 10;
	}
	while (div != 1)
	{
		div /= 10;
		tmp = nb / div + '0';
		flag->len += write(1, &tmp, 1);
		nb %= div;
	}
}