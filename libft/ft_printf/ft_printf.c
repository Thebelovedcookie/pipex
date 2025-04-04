/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahfoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 09:05:26 by mmahfoud          #+#    #+#             */
/*   Updated: 2024/02/01 11:30:21 by mmahfoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"
#include <stdio.h>

void	ft_input(char c, va_list args, int *n)
{
	if (c == 'c')
		ft_putchar(va_arg(args, int), n);
	if (c == 's')
		ft_putstr_printf(va_arg(args, char *), n);
	if (c == 'p')
		ft_put_ptr(va_arg(args, long unsigned int), n);
	if (c == 'd')
		ft_putnbr(va_arg(args, int), n, 'f');
	if (c == 'i')
		ft_putnbr(va_arg(args, int), n, 'f');
	if (c == 'u')
		ft_putnbr(va_arg(args, unsigned int), n, 't');
	if (c == 'x')
		ft_put_hexa(va_arg(args, unsigned int), n, 0);
	if (c == 'X')
		ft_put_hexa(va_arg(args, unsigned int), n, 1);
	if (c == '%')
		ft_putchar('%', n);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		i;
	int		n;

	va_start(args, input);
	i = 0;
	n = 0;
	while (input[i])
	{
		if (input[i] != '%')
			ft_putchar(input[i], &n);
		if (input[i] == '%')
		{
			ft_input(input[i + 1], args, &n);
			i++;
		}
		i++;
	}
	va_end(args);
	return (n);
}
