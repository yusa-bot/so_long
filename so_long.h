/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayusa <ayusa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 20:45:19 by ayusa             #+#    #+#             */
/*   Updated: 2025/08/26 02:54:22 by ayusa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>

# include "mlx.h"
# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include "./get_next_line/get_next_line.h"

# define MAP_SIZE 1024

typedef struct s_so_long
{
	int		fd;
	char	*file;
	char	**map;
	size_t	map_h;
	size_t	map_w;
	int		map_i_h;
	int		map_i_w;

	void	*mlx;
	void	*win;

	void	*img_1;
	void	*img_0;
	void	*img_p;
	void	*img_c;
	void	*img_e;

	int		t_size;
	int		player_x;
	int		player_y;
	int		collect_count;
	int		move_count;
}	t_so_long;

void	error_exit(t_so_long *dt, char *msg);
void	free_exit(t_so_long *dt);

void	free_map(char **map);
void	read_map(t_so_long *dt);
void	valid_map(t_so_long *dt);
void	check_path(t_so_long *dt);

void	so_long(t_so_long *dt);
void	display_map(t_so_long *dt);

int		handle_key(int keycode, void *param);
void	render_map(t_so_long *dt);
int		handle_exit(void *param);

#endif
