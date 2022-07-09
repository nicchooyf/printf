/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:04:54 by nchoo             #+#    #+#             */
/*   Updated: 2022/07/10 02:05:18 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

#include "libft/libft.h"

typedef struct s_pf
{
	va_list	arg;
	char 	*str;
	char	c;
	int	len;
	int	dash;
	int zero;
	int dot;
	int	star;
	int	hash;
	int type;
}	f_pf;

int ft_printstr(char *s);

#endif
