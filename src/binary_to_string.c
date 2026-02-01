/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_to_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 13:45:59 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/01 14:17:18 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	binary_to_string(char *buf, size_t len)
{
	const char	charset[]
		= "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	size_t		i;

	i = 0;
	while (i < len)
	{
		buf[i] = charset[(unsigned char)buf[i] % 62];
		i++;
	}
	return (0);
}
