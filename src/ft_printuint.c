/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 14:16:36 by nchoo             #+#    #+#             */
/*   Updated: 2022/07/16 14:43:28 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 *	
 */
void	ft_printuint(f_pf *flag)
{
	unsigned int	nb;
	
	nb = va_arg(flag->arg, unsigned int);
	if (!nb)
	{
		flag->len += write(1, "0", 1);
		return ;
	}
	ft_putnbr(flag, (size_t) nb);
}