/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayusa <ayusa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 17:24:31 by ayusa             #+#    #+#             */
/*   Updated: 2025/08/25 16:32:36 by ayusa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_copy(t_so_long *dt)
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

void	find_player(t_so_long *dt, size_t *x, size_t *y)
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
				*y = i;
				*x = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	dfs(char **map, size_t x, size_t y)
{
	if (map[x][y] == '1' || map[x][y] == 'V')
		return ;
	map[x][y] = 'V';
	dfs(map, x + 1, y);
	dfs(map, x - 1, y);
	dfs(map, x, y + 1);
	dfs(map, x, y - 1);
}

void	check_path(t_so_long *dt)
{
	char	**copy_map;
	size_t	x;
	size_t	y;

	copy_map = map_copy(dt);
	find_player(dt, &x, &y);
	dfs(copy_map, x, y);
	x = 0;
	while (x <= dt->map_h - 1)
	{
		y = 0;
		while (y <= dt->map_w - 3)
		{
			if (copy_map[x][y] == 'C' || copy_map[x][y] == 'E')
			{
				free_map(copy_map);
				error_exit(dt, "Unreachable C or E");
			}
			y++;
		}
		x++;
	}
	free_map(copy_map);
}
