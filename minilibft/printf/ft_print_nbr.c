/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkabat <wkabat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:46:45 by wkabat            #+#    #+#             */
/*   Updated: 2024/04/12 11:58:24 by wkabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	else if (n < 0)
	{
		len += write(1, "-", 1);
		len += ft_print_nbr(-n);
	}
	else if (n >= 10)
	{
		len += ft_print_nbr(n / 10);
		len += ft_print_char(n % 10 + '0');
	}
	else
		len += ft_print_char(n + '0');
	return (len);
}
