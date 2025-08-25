/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayusa <ayusa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 21:10:36 by ayusa             #+#    #+#             */
/*   Updated: 2025/08/25 16:18:24 by ayusa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_so_long *dt, void *img, int x, int y)
{
	mlx_put_image_to_window(
		dt->mlx, dt->win, img,
		x * dt->t_size, y * dt->t_size);
}

void	render_map(t_so_long *dt)
{
	int		y;
	int		x;
	char	tile;

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
	printf("%p\n", dt->img_0);
}

void	load_images(t_so_long *dt)
{
	dt->img_1 = mlx_xpm_file_to_image(
			dt->mlx, "assets/1.xpm", &dt->t_size, &dt->t_size);
	if (!dt->img_1)
		error_exit(dt, "Failed to load 1.xpm");
	dt->img_0 = mlx_xpm_file_to_image(
			dt->mlx, "assets/0.xpm", &dt->t_size, &dt->t_size);
	if (!dt->img_0)
		error_exit(dt, "Failed to load 0.xpm");
	dt->img_p = mlx_xpm_file_to_image(
			dt->mlx, "assets/p.xpm", &dt->t_size, &dt->t_size);
	if (!dt->img_p)
		error_exit(dt, "Failed to load p.xpm");
	dt->img_c = mlx_xpm_file_to_image(
			dt->mlx, "assets/c.xpm", &dt->t_size, &dt->t_size);
	if (!dt->img_c)
		error_exit(dt, "Failed to load c.xpm");
	dt->img_e = mlx_xpm_file_to_image(
			dt->mlx, "assets/e.xpm", &dt->t_size, &dt->t_size);
	if (!dt->img_e)
		error_exit(dt, "Failed to load e.xpm");
	render_map(dt);
}

void	display_map(t_so_long *dt)
{
	dt->map_i_h = (int)dt->map_h;
	dt->map_i_w = (int)dt->map_w;
	dt->mlx = mlx_init();
	if (!dt->mlx)
		error_exit(dt, "Failed to initialize MLX");
	dt->win = mlx_new_window(
			dt->mlx, dt->map_i_w * dt->t_size,
			dt->map_i_h * dt->t_size, "<game title>");
	if (!dt->win)
		error_exit(dt, "Failed to create window");
	load_images(dt);
}
