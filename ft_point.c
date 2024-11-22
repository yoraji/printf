/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoraji <yoraji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 22:37:45 by yoraji            #+#    #+#             */
/*   Updated: 2024/11/19 14:16:24 by yoraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_pointer(unsigned long c)
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

int	ft_point(void *num, char *base)
{
	unsigned long	number;
	char			*ptr;
	int				count;

	if (!num)
		return (ft_putstr("(nil)"));
	count = ft_putstr("0x");
	number = (unsigned long)num;
	count += count_pointer(number);
	ptr = malloc(count + 1);
	if (!ptr)
		return (0);
	ptr[count] = '\0';
	if (number == 0)
		return (ptr[0] = '0', free(ptr), 1);
	while (number > 0)
	{
		ptr[--count] = base[number % 16];
		number /= 16;
	}
	while (ptr[count])
		write(1, &ptr[count++], 1);
	return (free(ptr), count);
}

// #include <stdio.h>
// int main(void)
// {
//     unsigned int ptr = (unsigned int)&ptr;
//     ft_printf("\n%p\n", 0);
//     printf("\n%p\n", 0);
//     return (0);
// }