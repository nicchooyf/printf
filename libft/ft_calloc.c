/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 11:56:40 by nchoo             #+#    #+#             */
/*   Updated: 2022/07/07 18:27:34 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*res;

	if (n >= SIZE_MAX || size >= SIZE_MAX)
		return (NULL);
	res = malloc(n * size);
	if (!res)
		return (NULL);
	ft_bzero(res, (n * size));
	return (res);
}
