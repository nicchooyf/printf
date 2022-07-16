/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 13:01:58 by nchoo             #+#    #+#             */
/*   Updated: 2022/07/16 20:55:47 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 *	Get print length to pass into width functions
 */
static int get_length(long long int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		i++;
		nb *= -1;
	}
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

/*
 *	1, 22, 23, 25, 29
 */
void	ft_printint(f_pf *flag)
{
	long long int	nb;
	int	len;
	
	nb = va_arg(flag->arg, int);
	len = get_length(nb);
	check_left(flag, len);
	if (nb < 0)
	{
		flag->len += write(1, "-", 1);
		nb = -nb;
	}
	if (nb)
		ft_putnbr(flag, (size_t) nb);
	else
		flag->len += write(1, "0", 1);
	check_right(flag, len);
}