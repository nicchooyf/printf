/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 14:16:36 by nchoo             #+#    #+#             */
/*   Updated: 2022/07/17 21:31:17 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int get_length(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

void	ft_printuint(f_pf *flag)
{
	unsigned int	nb;
	int	len;
	
	nb = va_arg(flag->arg, unsigned int);
	len = get_length(nb);
	check_left(flag, len);
	len = check_precision_uint(flag, len, nb);
	check_zero(flag, len);
	if (nb)
		ft_putnbr(flag, (size_t)nb);
	else if (!flag->dot || flag->precision > 0)
		flag->len += write(1, "0", 1);
	check_right(flag, len);
}