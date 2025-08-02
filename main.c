/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayusa <ayusa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 20:45:21 by ayusa             #+#    #+#             */
/*   Updated: 2025/08/02 19:42:36 by ayusa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_so_long	dt;

	dt.fd = -1;
	dt.map = NULL;
	if (ac != 2)
		error_exit(&dt, "Usage: ./so_long <map_file.ber>");
	dt.file = av[1];
	read_map(&dt);
	so_long(&dt);
	return (0);
}
