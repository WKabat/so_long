/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkabat <wkabat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 10:53:32 by wkabat            #+#    #+#             */
/*   Updated: 2024/04/12 11:57:12 by wkabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int	ft_print_char(int c);
int	ft_print_str(char *str);
int	ft_print_percent(void);
int	ft_print_nbr(int n);
int	ft_print_hex(unsigned int n, const char format);
int	ft_print_unsigned(unsigned int n);
int	ft_print_ptr(void *str);
int	ft_printf(const char *str, ...);

#endif