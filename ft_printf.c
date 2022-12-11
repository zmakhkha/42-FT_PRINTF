/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 12:11:12 by zmakhkha          #+#    #+#             */
/*   Updated: 2022/12/11 10:06:47 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check(char c, int *len, va_list args)
{
	if (c == '%')
		*len += write(1, "%", 1);
	else if (c == 'c')
		ft_putchar_len(va_arg(args, int), len);
	else if ((c == 'd') || (c == 'i'))
		ft_putnbr_len(va_arg(args, int), len);
	else if (c == 'u')
		ft_putun_len(va_arg(args, unsigned int), len);
	else if (c == 's')
		ft_putstr_len(va_arg(args, char *), len);
	else if (c == 'p')
	{
		ft_putstr_len("0x", len);
		ft_dec_to_hex_ptr(va_arg(args, unsigned long int), len);
	}
	else if (c == 'x')
		ft_dec_to_hex(va_arg(args, unsigned int), 0, len);
	else if (c == 'X')
		ft_dec_to_hex(va_arg(args, unsigned int), 1, len);
	else
		ft_putchar_len(c, len);
}

int	ft_printf(char *str, ...)
{
	int		len;
	va_list	args;
	int		i;

	va_start(args, str);
	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			ft_check(str[i + 1], &len, args);
		i++;
		}
		else
			ft_putchar_len(str[i], &len);
		i++;
	}
	va_end(args);
	return (len);
}
