/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   av_to_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayusa <ayusa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 18:55:35 by ayusa             #+#    #+#             */
/*   Updated: 2025/07/19 18:13:55 by ayusa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_dup_p_e(t_so_long *dt)
{
	int	i;
	int	j;
	int	p;
	int	e;

	i = 0;
	p = 0;
	e = 0;
	while (dt->map[i])
	{
		j = 0;
		while (dt->map[i][j])
		{
			if (dt->map[i][j] == 'P')
				p++;
			else if (dt->map[i][j] == 'E')
				e++;
			j++;
		}
		i++;
	}
	if (p != 1 || e != 1)
		error_exit(dt, "The number of 'P' and 'E' is one");
}

void	map_surr_wall(t_so_long *dt)
{
	size_t	i;

	if (!dt->map || dt->map_w == 0 || dt->map_h == 0)
        error_exit(dt, "Invalid map size");
	i = 0;
	//printf("%c\n", dt->map[0][34]);//
	while (i <= dt->map_w - 3)
	{
		if (dt->map[0][i] != '1' || dt->map[dt->map_h - 1][i] != '1')
			error_exit(dt, "Top or bottom wall is not closed");
		i++;
	}
	i = 0;
	while (i <= dt->map_h - 1)
	{
		if (dt->map[i][0] != '1' || dt->map[i][dt->map_w - 3] != '1')
			error_exit(dt, "Left or right wall is not closed");
		i++;
	}
}

void	map_is_rectangular(t_so_long *dt)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (i <= dt->map_h - 1)
	{
		len = ft_strlen(dt->map[i]) + 1;//full
		//printf("len: %zu, map_w: %zu\n", len, dt->map_w);//
		if (i == dt->map_h - 1)//last line add (new line)
			len++;
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

void	line_to_map(t_so_long *dt, char *line, size_t i)
{
	size_t	j;

	dt->map[i] = malloc(dt->map_w);
	if (!dt->map[i])
		error_exit(dt, "can't malloc map line");
	dt->map[i][dt->map_w] = '\0';
	j = 0;
	while (line[j] != '\0')
	{
		dt->map[i][j] = line[j];//line + "\n"
		j++;
	}
	line[j] = '\0';
}

char	**read_file_all(t_so_long *dt)
{
	char	*line;
	size_t		i;

	dt->map = malloc(sizeof(char *) * MAP_SIZE);
	if (!dt->map)
		error_exit(dt, "can't malloc map");
	i = 0;
	while (1)
	{
		line = get_next_line(dt->fd);
		if (!line)
			break;
		//printf("i: %zu, line: %s\n", i, line);//
		if (i == 0)
			dt->map_w = ft_strlen(line) + 1;//line + "\n"
		line_to_map(dt, line, i);
		free(line);
		i++;
	}
	dt->map_h = i;
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
	valid_map(dt);
	return (dt->map);
}
