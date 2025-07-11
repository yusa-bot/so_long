/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayusa <ayusa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 20:45:21 by ayusa             #+#    #+#             */
/*   Updated: 2025/07/11 22:22:44 by ayusa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_so_long *dt)
{
	int	i;

	i = 0;
	if (!dt->map)
		return ;

	while (dt->map[i])
		free(dt->map[i++]);
	free(dt->map);
}

void	error_exit(t_so_long *dt, char *msg)
{
	int	len;

	if (dt->fd >= 0)
		close(dt->fd);

	if (dt->map)
		free_map(dt);

	len = ft_strlen(msg);
	write(2, "Error\n", 6);
	write(2, msg, len);
	write(2, "\n", 1);
	exit(1);
}

// void	valid_map(t_so_long *dt)
// {
// 	//P/E の重複
// 	//マップが壁で囲まれていない
// 	//マップ内に有効なパスがない
// 	//長方形
// }

char	**read_file_all(t_so_long *dt)
{
	char	*line;
	int		i;

	dt->map = malloc(sizeof(char *) * MAP_SIZE);
	if (!dt->map)
		error_exit(dt, "can't malloc map");

	i = 0;
	while (1)
	{
		line = get_next_line(dt->fd);
		if (!line)
			break;
		dt->map[i++] = line;
	}

	dt->map[i] = NULL;
	return (dt->map);
}

char	**read_map(t_so_long *dt)
{
	dt->fd = open(dt->file, O_RDONLY);
	if (dt->fd < 0)
		error_exit(dt, "can't open file");

	dt->map = read_file_all(dt);
	if (!dt->map)
		error_exit(dt, "Failed to read file");

	close(dt->fd);

	//valid_map(dt->map);
	return (dt->map);
}

int	main(int ac, char **av)
{
	t_so_long	dt;

	dt.fd = -1;
	dt.map = NULL;
	if (ac != 2)
		error_exit(&dt, "Usage: ./so_long <map_file.ber>");
	dt.file = av[1];
	read_map(&dt);

	// int i = 0;
	// while (dt.map[i])
	// 	printf("%s", dt.map[i++]);

	
	free_map(&dt);
}