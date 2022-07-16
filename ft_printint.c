/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 13:01:58 by nchoo             #+#    #+#             */
/*   Updated: 2022/07/16 14:05:59 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
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
static void	ft_putint(f_pf *flag, size_t nb)
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

/*
 *	1, 22, 23, 25, 29
 */
void	ft_printint(f_pf *flag)
{
	long long int	nb;
	
	nb = va_arg(flag->arg, int);
	if (nb < 0)
	{
		flag->len += write(1, "-", 1);
		nb = -nb;
	}
	if (!nb)
	{
		flag->len += write(1, "0", 1);
		return ;
	}
	ft_putint(flag, (size_t) nb);
}