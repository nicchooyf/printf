/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:11:15 by nchoo             #+#    #+#             */
/*   Updated: 2022/07/16 18:51:19 by nchoo            ###   ########.fr       */
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
	if (!flag->left && flag->width)
		ft_pad_width(flag, len);
	while (str[i])
		write(1, &str[i++], 1);
	if (flag->left && flag->width)
		ft_pad_width(flag, len);
	return (i);
}