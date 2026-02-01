/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 13:50:54 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/02/01 20:24:01 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_mkstemp(char *template);

int	main(int argc, char *argv[])
{
	int	fd;

	if (argc != 2)
		return (1);
	fd = ft_mkstemp(argv[1]);
	if (fd == -1)
		return (1);
	ft_putstr_fd("hello, world!\n", fd);
	close(fd);
	return (0);
}
