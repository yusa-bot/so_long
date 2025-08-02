/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayusa <ayusa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 14:00:45 by ayusa             #+#    #+#             */
/*   Updated: 2025/08/02 19:15:25 by ayusa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_collectibles(t_so_long *dt)
{
	int	y;
	int	x;

	dt->collect_count = 0;
	y = 0;
	while (dt->map[y])
	{
		x = 0;
		while (dt->map[y][x])
		{
			if (dt->map[y][x] == 'C')
				dt->collect_count++;
			x++;
		}
		y++;
	}
}

void	so_long(t_so_long *dt)
{
	count_collectibles(dt);
	dt->move_count = 0;
	dt->t_size = 50;
	display_map(dt);
	mlx_hook(dt->win, 2, 1L << 0, handle_key, dt);
	mlx_hook(dt->win, 17, 0, handle_exit, dt);
	mlx_loop(dt->mlx);
}
