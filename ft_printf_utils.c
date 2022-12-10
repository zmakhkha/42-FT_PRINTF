/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 12:11:12 by zmakhkha          #+#    #+#             */
/*   Updated: 2022/12/10 20:16:48 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_putstr_len(char *s, int *len)
{
	int	i;
	int	n;

	if (s != NULL)
	{
		n = ft_strlen(s);
		i = 0;
		while (i < n)
		{
			ft_putchar_len(s[i], len);
			i++;
		}
	}
	else
		ft_putstr_len("(null)", len);
}

void	ft_putnbr_len(int n, int *len)
{
	if (n == 2147483647)
		ft_putstr_len("2147483647", len);
	else if (n == -2147483648)
		ft_putstr_len("-2147483648", len);
	else
	{
		if (n < 0)
		{
			ft_putchar_len('-', len);
			n *= -1;
		}
		if (n > 9)
		{
			ft_putnbr_len(n / 10, len);
		}
		ft_putchar_len((n % 10) + '0', len);
	}
}

void	ft_putun_len(unsigned int n, int *len)
{
	if (n > 9)
		ft_putun_len(n / 10, len);
	ft_putchar_len((n % 10) + '0', len);
}

void	ft_dec_to_hex(unsigned int a, int idx, int *len)
{
	char	tab[12];
	int		i;

	i = 0;
	if (!a)
		ft_putnbr_len(0, len);
	while (a)
	{
		tab[i] = a % 16;
		a /= 16;
		i++;
	}
	while (i--)
	{
		if (tab[i] > 9)
		{
			if (idx)
				ft_putchar_len(tab[i] % 10 + 'A', len);
			else
				ft_putchar_len(tab[i] % 10 + 'a', len);
		}
		else
			ft_putnbr_len(tab[i], len);
	}
}

void	ft_dec_to_hex_ptr(unsigned long int a, int idx, int *len)
{
	char	tab[12];
	int		i;

	i = 0;
	if (!a)
		ft_putnbr_len(0, len);
	while (a)
	{
		tab[i] = a % 16;
		a /= 16;
		i++;
	}
	while (i--)
	{
		if (tab[i] > 9)
		{
			if (idx)
				ft_putchar_len(tab[i] % 10 + 'A', len);
			else
				ft_putchar_len(tab[i] % 10 + 'a', len);
		}
		else
			ft_putnbr_len(tab[i], len);
	}
}
