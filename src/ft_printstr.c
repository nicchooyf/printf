/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:11:15 by nchoo             #+#    #+#             */
/*   Updated: 2022/07/16 20:54:27 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(f_pf *flag)
{
	int		i;
	int		len;
	char	*str;

	str = va_arg(flag->arg, char *);
	i = 0;
	if (!str)
	{
		flag->len += write(1, "(null)", 6);
		return (0);
	}
	len = ft_strlen(str);
	check_left(flag, len);
	while (str[i])
		write(1, &str[i++], 1);
	check_right(flag, len);
	return (i);
}