/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:04:54 by nchoo             #+#    #+#             */
/*   Updated: 2022/07/14 04:25:51 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "libft/libft.h"

typedef struct s_pf
{
	va_list	arg;
	int	wd;
	int	len;
	int	dash;
	int zero;
	int dot;
	int	star;
	int	hash;
	int type;
	int perc;
}	f_pf;

typedef int	(*ptr)(f_pf*);
typedef ptr	(*fn)(void);

int ft_printf(const char* flag, ...);
int	ft_printstr(f_pf *flag);
int ft_putchar(f_pf *flag);
int ft_check_flags(f_pf *flag, const char *str, int i);
int ft_check_type(f_pf *flag, const char *str, int i);
// int ft_sort_type(f_pf *flag, va_list arg);
// ptr ft_determine_type(f_pf *flag);

#endif