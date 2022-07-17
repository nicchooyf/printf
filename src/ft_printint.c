/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 13:01:58 by nchoo             #+#    #+#             */
/*   Updated: 2022/07/17 21:52:04 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 *	Get print length to pass into flag functions
 */
static int	get_length(long long int nb)
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
 *	
 */
void	ft_printint(f_pf *flag)
{
	long long int	nb;
	int				len;

	nb = va_arg(flag->arg, int);
	len = get_length(nb);
	check_left(flag, len);
	if (nb < 0)
	{
		if (flag->width > 0 || flag->precision > 0)
		{
			len -= 1;
			if (flag->width > 0)
				flag->width -= 1;
		}
		flag->len += write(1, "-", 1);
		nb = -nb;
	}
	len = check_precision_int(flag, len, nb);
	check_zero(flag, len);
	if (nb)
		ft_putnbr(flag, (size_t) nb);
	else if (!flag->dot || flag->precision > 0)
		flag->len += write(1, "0", 1);
	check_right(flag, len);
}
