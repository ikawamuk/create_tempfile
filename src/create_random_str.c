/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_random_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 13:45:05 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/01 14:16:44 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <stddef.h>

int	binary_to_string(char *buf, size_t len);

int	fill_random_str(char *ptr, size_t len)
{
	const int	rand_fd = open("/dev/urandom", O_RDONLY);
	char		buf[256];

	if (rand_fd == -1)
		return (-1);
	if (read(rand_fd, buf, len) < 0)
	{
		close(rand_fd);
		return (-1);
	}
	close(rand_fd);
	binary_to_string(buf, len);
	ft_memcpy(ptr, buf, len);
	return (0);
}
