/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:19:47 by nchoo             #+#    #+#             */
/*   Updated: 2022/07/14 22:29:55 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	int res;
	
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
	res = flag->len;
	va_end(flag->arg);
	free(flag);
	return (res);
}

// #define input "hello, %s again %s\n", "world!", "teehee"

// int main()
// {
// 	int mine = ft_printf(input);
// 	int actual = printf(input);

// 	printf("mine: %d, actual: %d\n", mine, actual);
// }