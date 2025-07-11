/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_lower.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:33:48 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/06/02 22:53:39 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_hex_lower(unsigned long n)
{
	char	*hex_digits_lower;
	int		char_count;

	char_count = 0;
	hex_digits_lower = "0123456789abcdef";
	if (n >= 16)
		char_count += ft_print_hex_lower(n / 16);
	char_count += ft_putchar(hex_digits_lower[n % 16]);
	return (char_count);
}
