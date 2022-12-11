/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:09:46 by zmakhkha          #+#    #+#             */
/*   Updated: 2022/12/11 09:12:15 by zmakhkha         ###   ########.fr       */
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

void	ft_putchar_len(char c, int *len)
{
	*len += 1;
	write(1, &c, 1);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
