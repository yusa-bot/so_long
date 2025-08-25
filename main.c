/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayusa <ayusa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 20:45:21 by ayusa             #+#    #+#             */
/*   Updated: 2025/08/25 21:49:34 by ayusa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_dt(t_so_long *dt)
{
	dt->mlx = NULL;
	dt->win = NULL;
	dt->img_1 = NULL;
	dt->img_0 = NULL;
	dt->img_p = NULL;
	dt->img_c = NULL;
	dt->img_e = NULL;
	dt->map = NULL;
	dt->file = NULL;
	dt->fd = -1;
	dt->map_w = 0;
	dt->map_h = 0;
	dt->player_x = 0;
	dt->player_y = 0;
	dt->collect_count = 0;
	dt->move_count = 0;
}

int	main(int ac, char **av)
{
	t_so_long	dt;

	init_dt(&dt);
	if (ac != 2)
		error_exit(&dt, "Usage: ./so_long <map_file.ber>");
	dt.file = av[1];
	read_map(&dt);
	so_long(&dt);
	return (0);
}
