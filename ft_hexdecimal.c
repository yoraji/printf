/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdecimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoraji <yoraji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 21:45:10 by yoraji            #+#    #+#             */
/*   Updated: 2024/11/20 15:55:15 by yoraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_hex(unsigned int c)
{
	int	count;

	if (c == 0)
		return (1);
	count = 0;
	while (c > 0)
	{
		count++;
		c /= 16;
	}
	return (count);
}

int	ft_hexdecimal(unsigned long num, int c, char *base, char *BASE)
{
	char	*ptr;
	int		count;

	count = count_hex(num);
	ptr = malloc(count + 1);
	if (!ptr)
		return (0);
	ptr[count] = '\0';
	if (num == 0)
		return (free(ptr), ft_putchar('0'), 1);
	while (num > 0)
	{
		if (c == 'x')
			ptr[--count] = base[num % 16];
		else
			ptr[--count] = BASE[num % 16];
		num /= 16;
	}
	while (ptr[count])
		write(1, &ptr[count++], 1);
	return (free(ptr), count);
}
