/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayusa <ayusa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 21:10:36 by ayusa             #+#    #+#             */
/*   Updated: 2025/07/29 21:13:21 by ayusa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//windowに描画
void	put_image(t_so_long *dt, void *img, int x, int y)
{
	mlx_put_image_to_window(dt->mlx, dt->win, img, x * dt->t_size, y * dt->t_size);
}

//5種類を分岐
void	render_map(t_so_long *dt)
{
	int	y;
	int	x;
	char tile;

	y = 0;
	while (dt->map[y])
	{
		x = 0;
		while (dt->map[y][x])
		{
			tile = dt->map[y][x];
			if (tile == '1')
				put_image(dt, dt->img_1, x, y);
			else if (tile == '0')
				put_image(dt, dt->img_0, x, y);
			else if (tile == 'P')
				put_image(dt, dt->img_p, x, y);
			else if (tile == 'C')
				put_image(dt, dt->img_c, x, y);
			else if (tile == 'E')
				put_image(dt, dt->img_e, x, y);
			x++;
		}
		y++;
	}
}

//1tileごとをimageに変換
void	load_images(t_so_long *dt)
{
	dt->img_1 = mlx_xpm_file_to_image(dt->mlx, "aseets/1.xpm", &dt->t_size, &dt->t_size);
	dt->img_0 = mlx_xpm_file_to_image(dt->mlx, "aseets/0.xpm", &dt->t_size, &dt->t_size);
	dt->img_p = mlx_xpm_file_to_image(dt->mlx, "aseets/p.xpm", &dt->t_size, &dt->t_size);
	dt->img_c = mlx_xpm_file_to_image(dt->mlx, "aseets/c.xpm", &dt->t_size, &dt->t_size);
	dt->img_e = mlx_xpm_file_to_image(dt->mlx, "aseets/e.xpm", &dt->t_size, &dt->t_size);
	render_map(dt);
}

//親
void	display_map(t_so_long *dt)
{
	dt->map_i_h = (int)dt->map_h;
	dt->map_i_w = (int)dt->map_w;
	dt->mlx = mlx_init();
	dt->win = mlx_new_window(dt->mlx, dt->map_i_w * dt->t_size, dt->map_i_h * dt->t_size, "<game title>");
	load_images(dt);
}
