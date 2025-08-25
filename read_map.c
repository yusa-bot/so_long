/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayusa <ayusa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 18:55:35 by ayusa             #+#    #+#             */
/*   Updated: 2025/08/25 22:28:45 by ayusa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	line_to_map(t_so_long *dt, char *line, size_t i)
{
	size_t	j;

	dt->map[i] = malloc(dt->map_w + 1);
	if (!dt->map[i])
	{
		error_exit(dt, "can't malloc map line");
		free(line);
	}
	dt->map[i][dt->map_w] = '\0';
	j = 0;
	while (line[j] != '\0')
	{
		dt->map[i][j] = line[j];
		j++;
	}
	dt->map[i][j] = '\0';
}

void	read_file_all(t_so_long *dt)
{
	char		*line;
	size_t		i;

	dt->map = malloc(sizeof(char *) * MAP_SIZE);
	if (!dt->map)
		error_exit(dt, "can't malloc map");
	i = 0;
	while (1)
	{
		line = get_next_line(dt->fd);
		if (!line)
			break ;
		if (i == 0)
			dt->map_w = ft_strlen(line);
		line_to_map(dt, line, i);
		free(line);
		i++;
	}
	dt->map_h = i;
	dt->map[i] = NULL;
}

void	read_map(t_so_long *dt)
{
    dt->fd = open(dt->file, O_RDONLY);
	if (dt->fd < 0)
		error_exit(dt, "can't open file");
	read_file_all(dt);
	close(dt->fd);
	valid_map(dt);
}
