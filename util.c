/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayusa <ayusa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 18:56:09 by ayusa             #+#    #+#             */
/*   Updated: 2025/08/02 19:36:25 by ayusa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
		free(map[i++]);
	free(map);
}

void	free_exit(t_so_long *dt)
{
	printf("Exiting game...\n");
	if (dt->fd >= 0)
		close(dt->fd);
	if (dt->mlx)
	{
		mlx_destroy_display(dt->mlx);
		free(dt->mlx);
	}
	if (dt->map)
	{
		printf("Freeing map...\n");
		free_map(dt->map);
	}
	if (dt->win)
		mlx_destroy_window(dt->mlx, dt->win);
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
	exit(0);
}

void	error_exit(t_so_long *dt, char *msg)
{
	int	len;

	if (dt->fd >= 0)
		close(dt->fd);
	if (dt->mlx)
	{
		mlx_destroy_display(dt->mlx);
		free(dt->mlx);
	}
	if (dt->map)
		free_map(dt->map);
	if (dt->win)
		mlx_destroy_window(dt->mlx, dt->win);
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
	len = ft_strlen(msg);
	write(2, "Error\n", 6);
	write(2, msg, len);
	write(2, "\n", 1);
	exit(1);
}
