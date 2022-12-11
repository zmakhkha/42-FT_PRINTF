/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 12:11:12 by zmakhkha          #+#    #+#             */
/*   Updated: 2022/12/11 09:22:14 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

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

void	ft_dec_to_hex_ptr(unsigned long int a, int *len)
{
	char				*tab;
	int					l;
	int					i;

	l = 0;
	if (!a)
		ft_putnbr_len(0, len);
	get_int_hex_len(a, &l);
	tab = ft_calloc(1, l + 1);
	i = 0;
	while (i < l)
	{
		tab[i] = a % 16;
		a /= 16;
		i++;
	}
	while (i--)
	{
		if (tab[i] > 9)
			ft_putchar_len(tab[i] % 10 + 'a', len);
		else
			ft_putnbr_len(tab[i], len);
	}
	free(tab);
}

void	get_int_hex_len(unsigned long int nbr, int *lenght)
{
	while (nbr)
	{
		nbr /= 16;
		*lenght += 1;
	}
}
