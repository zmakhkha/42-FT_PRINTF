/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 12:07:27 by zmakhkha          #+#    #+#             */
/*   Updated: 2022/12/11 09:19:39 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

size_t	ft_strlen(const char *s);

void	get_int_hex_len(unsigned long int nbr, int *lenght);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
void	ft_putchar_len(char c, int *len);
void	ft_putstr_len(char *s, int *len);
void	ft_putnbr_len(int n, int *len);
void	ft_putun_len(unsigned int n, int *len);
void	ft_dec_to_hex(unsigned int a, int idx, int *len);
void	ft_dec_to_hex_ptr(unsigned long int a, int *len);
void	ft_check(char c, int *len, va_list args);
int		ft_printf(char *str, ...);

#endif