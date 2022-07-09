/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:19:47 by nchoo             #+#    #+#             */
/*   Updated: 2022/07/10 02:24:41 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static f_pf *ft_struct_init(f_pf *flag)
{
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

size_t	ft_printf(char *str, ...)
{
	size_t		i;
	f_pf		flag;
	va_list		p;
	
	ft_struct_init(&flag);
	i = 0;
	va_start(p, str);
	while (str[i])
	{
		if (str[i] == '%')
			{
				return 0;
			}
		else
			flag.len += write(1, &str[i], 1);
		i++;
	}
	va_end(p);
	return (flag.len);
}

#define input "hello, world!\n"

int main()
{
	
	size_t mine = ft_printf(input);
	size_t actual = printf(input);

	printf("mine: %ld, actual: %ld\n", mine, actual);
}