/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:19:47 by nchoo             #+#    #+#             */
/*   Updated: 2022/07/14 04:39:39 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static f_pf *ft_struct_init(f_pf *flag)
{
	flag->wd = 0;
	flag->perc = 0;
	flag->dash = 0;
	flag->dot = 0;
	flag->hash = 0;
	flag->len = 0;
	flag->star = 0;
	flag->type = 0;
	flag->zero = 0;
	return (flag);
}

int	ft_printf(const char *str, ...)
{
	f_pf		*flag;
	int	i;
	
	flag = malloc(sizeof(f_pf));
	if (!flag)
		return (-1);
	ft_struct_init(flag);
	va_start(flag->arg, str);
	i = -1;
	while (str[++i])
	{
		if (str[i] == '%' && str[i + 1])
			i = ft_check_flags(flag, str, i + 1);
		else
			flag->len += write(1, &str[i], 1);
	}
	va_end(flag->arg);
	return (flag->len);
}

#define input "hello, %s\n", "world!"

int main()
{
	
	int mine = ft_printf(input);
	int actual = printf(input);

	printf("mine: %d, actual: %d\n", mine, actual);
}