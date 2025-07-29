/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayusa <ayusa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 14:00:45 by ayusa             #+#    #+#             */
/*   Updated: 2025/07/29 18:25:18 by ayusa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	add_data_struct(t_so_long *dt)
{
	dt->map_i_h = (int)dt->map_h;
	dt->map_i_w = (int)dt->map_w;

}

so_long(t_so_long *dt)
{
	add_data_struct(dt);

	dt->mlx = mlx_init();

	dt->win = mlx_new_window(dt->mlx, dt->map_i_w, dt->map_i_h, "<game title>");
}