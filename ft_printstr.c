/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:11:15 by nchoo             #+#    #+#             */
/*   Updated: 2022/07/14 04:38:14 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printstr(f_pf *flag)
{
	int	i;
	char *str;

	str = va_arg(flag->arg, char *);
	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
	return (i);
}