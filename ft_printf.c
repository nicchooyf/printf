/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:19:47 by nchoo             #+#    #+#             */
/*   Updated: 2022/07/09 16:43:46 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t	ft_printf(char *str, ...)
{
	size_t		i;
	size_t		sum;
	va_list		p;
	

	i = 0;
	sum = 0;
	va_start(p, str);
	while (str[i])
	{
		if (str[i] == '%')
			{
				return 0;
			}
		else
			sum += write(1, &str[i], 1);
		i++;
	}
	va_end(p);
	return (sum);
}