/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:04:54 by nchoo             #+#    #+#             */
/*   Updated: 2022/07/16 19:16:19 by nchoo            ###   ########.fr       */
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
	int	len;
	int hexlen;
	int	left;
	int zero;
	int dot;
	int	star;
	int	hash;
	int type;
	int perc;
}	f_pf;

// typedef int	(*ptr)(f_pf*);
// typedef ptr	(*fn)(void);

int ft_printf(const char* flag, ...);
int	ft_printstr(f_pf *flag);
int	ft_printchar(f_pf *flag);
void	ft_putnbr_base(t_ull point, f_pf *flag, char *base);
void	ft_putnbr(f_pf *flag, size_t nb);
void	ft_printptr(f_pf *flag);
void	ft_printint(f_pf *flag);
void	ft_printuint(f_pf *flag);
void	ft_printhex(f_pf *flag);
int ft_check_flags(f_pf *flag, const char *str, int i);
int ft_check_type(f_pf *flag, const char *str, int i);
void	ft_pad_width(f_pf *flag, int len);
// int ft_sort_type(f_pf *flag, va_list arg);
// ptr ft_determine_type(f_pf *flag);

#endif