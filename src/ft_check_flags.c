/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 04:17:54 by nchoo             #+#    #+#             */
/*   Updated: 2022/07/16 20:05:03 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
 
 /*
  *	parses through the string and updates the corresponding flag's value 
  *	in the struct if they are found
  */
int ft_check_flags(f_pf *flag, const char *str, int i)
{
	while (!ft_strchr("cspdiuxX%", str[i]))
	{
		if (str[i] == '-' && ++i)
			flag->left = 1;
		if (ft_isdigit(str[i]))
			while (ft_isdigit(str[i]))
				flag->width = flag->width * 10 + (str[i++] - '0');
	}
	return (ft_check_type(flag, str, i));
}

int ft_check_type(f_pf *flag, const char *str, int i)
{
	if (str[i] == 'c')
		flag->len += ft_printchar(flag);
	else if (str[i] == 's')
		flag->len += ft_printstr(flag);
	else if (str[i] == 'p')
		ft_printptr(flag);
	else if (str[i] == 'i' || str[i] == 'd')
		ft_printint(flag);
	else if (str[i] == 'u')
		ft_printuint(flag);
	else if (str[i] == 'x' || str[i] == 'X')
	{
		if (str[i] == 'X')
			flag->upper = 1;
		else
			flag->upper = 0;
		ft_printhex(flag);
	}
	else if (str[i] == '%')
		flag->len += write(1, "%", 1);
	return (i);
}