/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayusa <ayusa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 17:24:31 by ayusa             #+#    #+#             */
/*   Updated: 2025/09/12 15:04:32 by ayusa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**map_copy(t_so_long *dt)
{
	char	**copy;
	size_t	i;

	copy = malloc(sizeof(char *) * (dt->map_h + 1));
	if (!copy)
		error_exit(dt, "Failed to copy map");
	i = 0;
	while (i < dt->map_h)
	{
		copy[i] = ft_strdup(dt->map[i]);
		if (!copy[i])
			error_exit(dt, "strdup failed");
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static void	find_player(t_so_long *dt, size_t *x, size_t *y)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (dt->map[i])
	{
		j = 0;
		while (dt->map[i][j])
		{
			if (dt->map[i][j] == 'P')
			{
				*y = j;
				*x = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

static void	dfs(t_so_long *dt, char **map, size_t x, size_t y)
{
	if ((x <= 0 || x >= dt->map_h) || (y <= 0 || y >= dt->map_w))
		return ;
	if (map[x][y] == '1' || map[x][y] == 'V')
		return ;
	map[x][y] = 'V';
	dfs(dt, map, x + 1, y);
	dfs(dt, map, x - 1, y);
	dfs(dt, map, x, y + 1);
	dfs(dt, map, x, y - 1);
}

void	check_path(t_so_long *dt)
{
	char	**copy_map;
	size_t	x;
	size_t	y;

	copy_map = map_copy(dt);
	find_player(dt, &x, &y);
	dfs(dt, copy_map, x, y);
	x = 0;
	while (x < dt->map_h)
	{
		y = 0;
		while (y < dt->map_w)
		{
			if (copy_map[x][y] == 'C' || copy_map[x][y] == 'E'
					|| copy_map[x][y] == 'P')
			{
				free_map(copy_map);
				error_exit(dt, "No valid path to all collectibles or exit");
			}
			y++;
		}
		x++;
	}
	free_map(copy_map);
}
