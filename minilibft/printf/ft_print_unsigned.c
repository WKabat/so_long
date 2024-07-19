/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkabat <wkabat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:36:50 by wkabat            #+#    #+#             */
/*   Updated: 2024/04/11 13:49:44 by wkabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// static int	ft_putchar(char c)
// {
// 	return (write(1, &c, 1));
// }

int	ft_print_unsigned(unsigned int n)
{
	unsigned int	len;

	len = 0;
	if (n >= 10)
	{
		len += ft_print_unsigned(n / 10);
		len += ft_print_char(n % 10 + '0');
	}
	else
		len += ft_print_char(n + '0');
	return (len);
}
