/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:19:47 by nchoo             #+#    #+#             */
/*   Updated: 2022/07/08 17:33:05 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t	ft_printf(char *str, ...)
{
	int			i;
	va_list		p;

	i = 0;
	va_start(p, str);
	while (str[i])
	{
		if (str[i] == '%')
			{
				return ;
			}
		else
			printstr(str);
	}
}
