/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 02:54:59 by nchoo             #+#    #+#             */
/*   Updated: 2022/07/14 02:15:20 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int ft_sort_type(f_pf *flag)
{
	ptr fn = ft_determine_type(flag);
	flag->len += fn(flag);
	return 0;
}

ptr ft_determine_type(f_pf *flag)
{
	if ((flag->str[flag->i]) == 'c')
		return &ft_putchar;
	return 0;
}