/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 13:01:58 by nchoo             #+#    #+#             */
/*   Updated: 2022/07/16 14:43:42 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	ft_putnbr(flag, (size_t) nb);
}