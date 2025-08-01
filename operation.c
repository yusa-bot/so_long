/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayusa <ayusa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 18:35:57 by ayusa             #+#    #+#             */
/*   Updated: 2025/08/01 20:03:32 by ayusa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// mlx_hook : 上下左右の移動
// WASD or 矢印キー : Pを移動
// 1 OK /0.C.E NG

void	move_player(t_so_long *dt, int dx, int dy)
{
	int	new_x = dt->player_x + dx;
	int	new_y = dt->player_y + dy;
	char	next = dt->map[new_y][new_x];

	if (next == '1') // 壁は移動不可
		return;
	if (next == 'C')
		dt->collect_count--;
	if (next == 'E')
	{
		if (dt->collect_count == 0)
		{
			ft_printf("Game Clear!\n");
			exit(0);
		}
		else
			return; // アイテム未取得なら無視
	}
	dt->map[dt->player_y][dt->player_x] = '0';
	dt->map[new_y][new_x] = 'P';
	dt->player_x = new_x;
	dt->player_y = new_y;
	dt->move_count++;
	ft_printf("Move count: %d\n", dt->move_count);
	render_map(dt);
}

int	handle_key(int keycode, t_so_long *dt)
{
	if (keycode == 65307)
		exit(0);//freeも。
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

int	handle_exit(t_so_long *dt)
{
	free_exit(dt);
	return (0);
}
