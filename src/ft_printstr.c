/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:11:15 by nchoo             #+#    #+#             */
/*   Updated: 2022/08/06 06:21:34 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 *	Function to print 's' type
 */
void	ft_printstr(t_pf *flag)
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
	len = check_precision_str(flag, len);
	check_left(flag, len);
	flag->len += write(1, str, len);
	check_right(flag, len);
}
