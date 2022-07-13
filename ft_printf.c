/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:19:47 by nchoo             #+#    #+#             */
/*   Updated: 2022/07/14 02:16:45 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static f_pf *ft_struct_init(f_pf *flag)
{
	flag->i = 0;
	flag->c = 0;
	flag->dash = 0;
	flag->dot = 0;
	flag->hash = 0;
	flag->len = 0;
	flag->star = 0;
	flag->str = 0;
	flag->type = 0;
	flag->zero = 0;
	return (flag);
}

size_t	ft_printf(const char *str, ...)
{
	f_pf		flag;
	va_list		p;
	
	ft_struct_init(&flag);
	flag.str = ft_strdup((char *)str);
	va_start(p, str);
	while (str[flag.i])
	{
		if (str[flag.i] == '%')
			{
				flag.i++;
				flag.len += ft_sort_type(&flag);
				return 0;
			}
		else
			flag.len += write(1, &str[flag.i], 1);
		flag.i++;
	}
	va_end(p);
	return (flag.len);
}

#define input "hello, world!%c\n"

int main()
{
	
	size_t mine = ft_printf(input);
	size_t actual = printf(input);

	printf("mine: %ld, actual: %ld\n", mine, actual);
}