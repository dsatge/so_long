/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsatge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:24:04 by dsatge            #+#    #+#             */
/*   Updated: 2023/12/28 18:31:31 by dsatge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <bsd/string.h>
# include <ctype.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdint.h>

unsigned int	ft_putunnbr(unsigned int n);
int				ft_putstr(char *s);
int				ft_putnbr(int n, int *len);
int				ft_hexputnbr(unsigned int n, char c);
int				ft_adress(void *str);
int				ft_putchar(char c);
int				check_type(char c, va_list args);
int				ft_printf(const char *c, ...);

#endif