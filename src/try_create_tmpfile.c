/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_create_tmpfile.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 13:44:10 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/01 14:14:53 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

int	fill_random_str(char *ptr, size_t len);

int	try_create_tmpfile(char *template)
{
	char	*x;
	size_t	len;

	x = ft_strchr(template, 'X');
	if (!x)
		return (-1);
	len = 0;
	while (x[len] == 'X' && len < 256)
		len++;
	if (fill_random_str(x, len) != 0)
		return (-1);
	return (open(template, O_CREAT | O_EXCL | O_RDWR));
}
