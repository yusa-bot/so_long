/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayusa <ayusa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 18:35:57 by ayusa             #+#    #+#             */
/*   Updated: 2025/08/25 23:27:18 by ayusa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	reset_player(t_so_long *dt, int new_x, int new_y)
{
	dt->map[dt->player_y][dt->player_x] = '0';
	dt->map[new_y][new_x] = 'P';
	dt->player_x = new_x;
	dt->player_y = new_y;
	dt->move_count++;
	ft_printf("Move: %d\n", dt->move_count);
}

void	move_player(t_so_long *dt, int dx, int dy)
{
	int		new_x;
	int		new_y;
	char	next;

	new_x = dt->player_x + dx;
	new_y = dt->player_y + dy;
	next = dt->map[new_y][new_x];
	if (next == '1')
		return ;
	if (next == 'C')
		dt->collect_count--;
	if (next == 'E')
	{
		if (dt->collect_count == 0)
		{
			ft_printf("Game Clear!\n");
			free_exit(dt);
		}
		else
			return ;
	}
	reset_player(dt, new_x, new_y);
	render_map(dt);
}

int	handle_key(int keycode, void *param)
{
	t_so_long *dt;

	dt = (t_so_long *)param;
	if (keycode == 65307)//esc
		free_exit(dt);
	else if (keycode == 'w' || keycode == 119)
		move_player(dt, 0, -1);
	else if (keycode == 's' || keycode == 115)
		move_player(dt, 0, 1);
	else if (keycode == 'a' || keycode == 97)
		move_player(dt, -1, 0);
	else if (keycode == 'd' || keycode == 100)
		move_player(dt, 1, 0);
	return (0);
}

int	handle_exit(void *param)
{
	t_so_long	*dt;

	printf("handle_exit called\n");
	dt = (t_so_long *)param;
	free_exit(dt);
	return (0);
}
