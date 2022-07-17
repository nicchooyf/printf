/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:11:15 by nchoo             #+#    #+#             */
/*   Updated: 2022/07/17 19:30:16 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// static int	check_precision_str(f_pf *flag, int len)
// {
// 	if (flag->dot)
// 		if (len > flag->precision)
// 			len = flag->precision;
// 	flag->precision = 0;
// 	flag->dot = 0;
// 	return (len);
// }

void	ft_printstr(f_pf *flag)
{
	int		len;
	char	*str;

	str = va_arg(flag->arg, char *);
	if (!str)
	{
		check_left(flag, 6);
		if (!flag->dot || flag->precision >= 6)
			flag->len += write(1, "(null)", 6);
		return ;
	}
	len = ft_strlen(str);
	check_left(flag, len);
	len = check_precision_str(flag, len);
	flag->len += write(1, str, len);
	check_right(flag, len);
}