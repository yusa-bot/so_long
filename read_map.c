/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayusa <ayusa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 18:55:35 by ayusa             #+#    #+#             */
/*   Updated: 2025/09/27 11:45:48 by ayusa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	line_to_map(t_so_long *dt, char *line, size_t i)
{
	size_t	j;
	size_t	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		len--;
	dt->map[i] = malloc(len + 1);
	if (!dt->map[i])
	{
		free(line);
		error_exit(dt, "can't malloc map line");
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

static void	research_map_w(t_so_long *dt, size_t line_len, char *line)
{
	if (line_len > dt->map_w)
	{
		if (line_len > DISPLAY_MAP_SIZE_X)
		{
			close(dt->fd);//
			free(dt->map);//
			dt->map = NULL;//
			free(line);//
			free(dt->last_str);//
			exit(1);//
		}
		dt->map_w = line_len;
	}
}

static void	read_file_all(t_so_long *dt)
{
	char		*line;
	size_t		i;
	size_t		len;

	dt->map = malloc(sizeof(char *) * (dt->map_h + 1));
	if (!dt->map)
		error_exit(dt, "can't malloc map");
	i = 0;
	while (1)
	{
		line = get_next_line(dt->fd, &dt->last_str);
		if (!line)
			break ;
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			len--;
		research_map_w(dt, len, line);
		line_to_map(dt, line, i);
		free(line);
		i++;
	}
	dt->map[i] = NULL;
	free(dt->last_str);
}

void	count_map_lines(t_so_long *dt)
{
	char	*line;
	size_t	count;

	count = 0;
	while (1)
	{
		line = get_next_line(dt->fd, &dt->last_str);
		if (!line)
			break ;
		free(line);
		count++;
	}
	if (count == 0)
		error_exit(dt, "map file is empty");
	if (count > DISPLAY_MAP_SIZE_Y)
		error_exit(dt, "map height is too large under display size 41");
	dt->map_h = count;
	free(dt->last_str);
}

void	read_map(t_so_long *dt)
{
	dt->fd = open(dt->file, O_RDONLY);
	if (dt->fd < 0)
		error_exit(dt, "can't open file");
	count_map_lines(dt);
	dt->fd = open(dt->file, O_RDONLY);
	if (dt->fd < 0)
		error_exit(dt, "can't open file");
	read_file_all(dt);
	close(dt->fd);
	valid_map(dt);
}
