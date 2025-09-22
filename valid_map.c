/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayusa <ayusa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 21:28:38 by ayusa             #+#    #+#             */
/*   Updated: 2025/09/12 15:10:09 by ayusa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	count_p_and_e(t_so_long *dt, int *p, int *e)
{
	int	i;
	int	j;

	i = 0;
	while (dt->map[i])
	{
		j = 0;
		while (dt->map[i][j])
		{
			if (dt->map[i][j] == 'P')
			{
				dt->player_x = j;
				dt->player_y = i;
				(*p)++;
			}
			else if (dt->map[i][j] == 'E')
				(*e)++;
			else if (dt->map[i][j] != '0' && dt->map[i][j] != '1'
				&& dt->map[i][j] != 'C')
				error_exit(dt, "Invalid character in map");
			j++;
		}
		i++;
	}
}

static void	map_dup_p_e(t_so_long *dt)
{
	int	p;
	int	e;

	p = 0;
	e = 0;
	count_p_and_e(dt, &p, &e);
	if (p != 1 || e != 1)
		error_exit(dt, "The number of 'P' and 'E' is not one");
}

static void	map_surr_wall(t_so_long *dt)
{
	size_t	i;

	if (!dt->map || dt->map_w == 0 || dt->map_h == 0)
		error_exit(dt, "Invalid map size");
	i = 0;
	while (i <= dt->map_w - 1)
	{
		if (dt->map[0][i] != '1' || dt->map[dt->map_h - 1][i] != '1')
			error_exit(dt, "Top or bottom wall is not closed");
		i++;
	}
	i = 0;
	while (i <= dt->map_h - 1)
	{
		if (dt->map[i][0] != '1' || dt->map[i][dt->map_w - 1] != '1')
			error_exit(dt, "Left or right wall is not closed");
		i++;
	}
}

static void	map_is_rectangular(t_so_long *dt)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (i <= dt->map_h - 1)
	{
		len = ft_strlen(dt->map[i]);
		if (len != dt->map_w)
			error_exit(dt, "The map must be rectangular");
		i++;
	}
}

void	valid_map(t_so_long *dt)
{
	map_dup_p_e(dt);
	map_surr_wall(dt);
	map_is_rectangular(dt);
	check_path(dt);
}
