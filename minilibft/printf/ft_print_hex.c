/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkabat <wkabat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:47:40 by wkabat            #+#    #+#             */
/*   Updated: 2024/04/11 14:01:39 by wkabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int n, const char format)
{
	unsigned int	len;

	len = 0;
	if (n >= 16)
	{
		len += ft_print_hex(n / 16, format);
		len += ft_print_hex(n % 16, format);
	}
	else
	{
		if (n < 10)
			len += ft_print_char(n + '0');
		else
		{
			if (format == 'x')
				len += ft_print_char(n - 10 + 'a');
			if (format == 'X')
				len += ft_print_char(n - 10 + 'A');
		}
	}
	return (len);
}
