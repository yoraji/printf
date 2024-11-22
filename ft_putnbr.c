/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoraji <yoraji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:56:26 by yoraji            #+#    #+#             */
/*   Updated: 2024/11/19 16:53:22 by yoraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_digit_len(int num)
{
	int	counter;

	if (num == 0)
		return (1);
	counter = 0;
	while (num)
	{
		counter++;
		num /= 10;
	}
	return (counter);
}

int	*extract(int c, int digit_len)
{
	int	*ptr;

	ptr = malloc(digit_len * sizeof(int));
	if (!ptr)
		return (0);
	while ((--digit_len) != -1)
	{
		ptr[digit_len] = c % 10;
		c /= 10;
	}
	return (ptr);
}

int	ft_putnbr(int c)
{
	int	count;
	int	*ptr;
	int	digit_len;
	int	save;

	count = 0;
	if (c == -2147483648)
		return (ft_putstr("-2147483648"));
	if (c == 0)
		return (ft_putchar('0'), 1);
	if (c < 0)
	{
		count += write(1, "-", 1);
		c = -c;
	}
	digit_len = ft_digit_len(c);
	save = digit_len;
	ptr = extract(c, digit_len);
	digit_len = 0;
	while (digit_len < save)
		ft_putchar(ptr[digit_len++] + '0');
	free(ptr);
	return (count + save);
}
