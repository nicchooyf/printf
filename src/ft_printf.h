/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:04:54 by nchoo             #+#    #+#             */
/*   Updated: 2022/08/05 03:35:03 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"

typedef unsigned long long	t_ull;
typedef struct s_pf
{
	va_list	arg;
	int upper;
	int	width;
	int pad;
	int	len;
	int hexlen;
	int	left;
	int zero;
	int precision;
	int	dot;
	int	star;
	int	hash;
	int space;
	int plus;
}	f_pf;

// typedef int	(*ptr)(f_pf*);
// typedef ptr	(*fn)(void);

int ft_printf(const char* flag, ...);
int	ft_printchar(f_pf *flag);
void	ft_putnbr_base(t_ull point, f_pf *flag, char *base);
void	ft_putnbr(f_pf *flag, size_t nb);
void	ft_printstr(f_pf *flag);
void	ft_printptr(f_pf *flag);
void	ft_printint(f_pf *flag);
void	ft_printuint(f_pf *flag);
void	ft_printhex(f_pf *flag);
int ft_check_flags(f_pf *flag, const char *str, int i);
int ft_check_type(f_pf *flag, const char *str, int i);
void	check_left(f_pf *flag, int len);
void	check_right(f_pf *flag, int len);
void	check_zero(f_pf *flag, int len);
void	ft_pad_space(f_pf *flag, int len);
void	ft_pad_zero(f_pf *flag, int len);
// int	check_precision_str(f_pf *flag, int len);
int	check_precision_int(f_pf *flag, int len, int nb);
int	check_precision_uint(f_pf *flag, int len, unsigned int nb);
// int ft_sort_type(f_pf *flag, va_list arg);
// ptr ft_determine_type(f_pf *flag);

#endif