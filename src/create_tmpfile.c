/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tmpfile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 13:19:33 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/01 13:59:20 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#define TRYAL_MAX 20

int	try_create_tmpfile(char *template);

/*
	allowde function: open, malloc, free
*/
int	create_tmpfile(char *template)
{
	int		fd;
	size_t	i;

	i = 0;
	while (i++ < TRYAL_MAX)
	{
		fd = try_create_tmpfile(template);
		if (fd != -1)
			return (fd);
	}
	return (-1);
}
