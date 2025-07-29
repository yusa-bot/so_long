/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayusa <ayusa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 20:45:19 by ayusa             #+#    #+#             */
/*   Updated: 2025/07/29 18:18:42 by ayusa            ###   ########.fr       */
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

#define MAP_SIZE 1024

typedef struct s_so_long
{
	int		fd;
	char	*file;
	char	**map;
	size_t	map_h;
	size_t	map_w;
	int		map_i_h;
	int		map_i_w;

	void			*mlx;
	void			*img;
	void			*win;
}	t_so_long;

void	error_exit(t_so_long *dt, char *msg);
void	free_map(char **map);
char	**read_map(t_so_long *dt);
void	check_path(t_so_long *dt);

#endif