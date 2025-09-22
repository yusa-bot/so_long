/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayusa <ayusa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 18:56:09 by ayusa             #+#    #+#             */
/*   Updated: 2025/09/12 15:06:59 by ayusa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

static void	free_images(t_so_long *dt)
{
	if (dt->img_1)
		mlx_destroy_image(dt->mlx, dt->img_1);
	if (dt->img_0)
		mlx_destroy_image(dt->mlx, dt->img_0);
	if (dt->img_p)
		mlx_destroy_image(dt->mlx, dt->img_p);
	if (dt->img_c)
		mlx_destroy_image(dt->mlx, dt->img_c);
	if (dt->img_e)
		mlx_destroy_image(dt->mlx, dt->img_e);
}

void	free_handle(t_so_long *dt)
{
	if (dt->img_0)
		free_images(dt);
	if (dt->mlx && dt->win)
	{
		mlx_clear_window(dt->mlx, dt->win);
		mlx_destroy_window(dt->mlx, dt->win);
		dt->win = NULL;
	}
	if (dt->mlx)
	{
		mlx_destroy_display(dt->mlx);
		free(dt->mlx);
		dt->mlx = NULL;
	}
	if (dt->fd >= 0)
		close(dt->fd);
	if (dt->map)
	{
		free_map(dt->map);
		dt->map = NULL;
	}
}

void	error_exit(t_so_long *dt, char *msg)
{
	int	len;

	if (dt->img_0)
		free_images(dt);
	if (dt->mlx && dt->win)
		mlx_destroy_window(dt->mlx, dt->win);
	if (dt->fd >= 0)
		close(dt->fd);
	if (dt->map)
	{
		free_map(dt->map);
		dt->map = NULL;
	}
	if (dt->mlx)
	{
		mlx_destroy_display(dt->mlx);
		free(dt->mlx);
		dt->mlx = NULL;
	}
	len = ft_strlen(msg);
	write(2, "Error\n", 6);
	write(2, msg, len);
	write(2, "\n", 1);
	exit(1);
}
