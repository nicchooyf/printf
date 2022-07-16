/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 02:54:59 by nchoo             #+#    #+#             */
/*   Updated: 2022/07/14 03:50:02 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int ft_sort_type(f_pf *flag, va_list arg)
{
	ptr fn = ft_determine_type(flag);
	flag->len += fn(flag);
	return 0;
}

ptr ft_determine_type(f_pf *flag)
{
	flag->c = flag->str[flag->i];
	if (flag->c == 'c')
		return &ft_putchar;
	return 0;
}