/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 04:17:54 by nchoo             #+#    #+#             */
/*   Updated: 2022/07/14 04:38:36 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int ft_check_flags(f_pf *flag, const char *str, int i)
{
	return (ft_check_type(flag, str, i));
}

int ft_check_type(f_pf *flag, const char *str, int i)
{
	if (str[i] == 'c')
		flag->len += ft_putchar(flag);
	else if (str[i] == 's')
		flag->len += ft_printstr(flag);
	return (i);
}