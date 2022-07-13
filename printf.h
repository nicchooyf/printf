/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:04:54 by nchoo             #+#    #+#             */
/*   Updated: 2022/07/14 02:11:01 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "libft/libft.h"

typedef struct s_pf
{
	va_list	arg;
	char 	*str;
	char	c;
	size_t	i;
	int	len;
	int	dash;
	int zero;
	int dot;
	int	star;
	int	hash;
	int type;
}	f_pf;

typedef int	(*ptr)(f_pf*);
typedef ptr	(*fn)(void);

int	ft_printstr(f_pf *flag);
int ft_putchar(f_pf *flag);
int ft_sort_type(f_pf *flag);
ptr ft_determine_type(f_pf *flag);

#endif