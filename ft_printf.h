/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 12:07:27 by zmakhkha          #+#    #+#             */
/*   Updated: 2022/12/10 20:14:36 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

size_t	ft_strlen(const char *s);

void	ft_putchar_len(char c, int *len);
void	ft_putstr_len(char *s, int *len);
void	ft_putnbr_len(int n, int *len);
void	ft_putun_len(unsigned int n, int *len);
void	ft_dec_to_hex(unsigned int a, int idx, int *len);
void	ft_dec_to_hex_ptr(unsigned long int a, int idx, int *len);
void	ft_check(char c, int *len, va_list args);
int		ft_printf(char *str, ...);

#endif