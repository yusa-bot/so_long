/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayusa <ayusa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 13:12:03 by ayusa             #+#    #+#             */
/*   Updated: 2025/07/19 14:53:14 by ayusa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_nl_line(char *last_str)
{
	int		i;
	char	*str;

	if (!last_str)
		return (NULL);
	i = 0;
	while (last_str[i] && last_str[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (last_str[i] && last_str[i] != '\n')
	{
		str[i] = last_str[i];
		i++;
	}
	if (last_str[i] == '\n')
	{
		str[i] = last_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*new_last_str(char *last_str)
{
	int		i;
	int		j;
	char	*str;

	if (!last_str)
		return (NULL);
	i = 0;
	while (last_str[i] && last_str[i] != '\n')
		i++;
	if (!last_str[i])
		return (free(last_str), NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(last_str) - i + 1));
	if (!str)
		return (free(last_str), NULL);
	i++;
	j = 0;
	while (last_str[i])
		str[j++] = last_str[i++];
	str[j] = '\0';
	free(last_str);
	return (str);
}

char	*init_buf_and_str(char **buf, char *last_str)
{
	if (!last_str)
		last_str = ft_strdup("");
	*buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!*buf)
		return (free(last_str), NULL);
	return (last_str);
}

char	*read_until_nl_in_buf(int fd, char *last_str)
{
	char	*buf;
	int		read_bytes;

	if (fd < 0)
		return (NULL);
	last_str = init_buf_and_str(&buf, last_str);
	if (!last_str)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(last_str, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes == -1)
			return (free(buf), free(last_str), NULL);
		buf[read_bytes] = '\0';
		last_str = to_new_last_str(last_str, buf);
		if (!last_str)
			return (free(buf), NULL);
	}
	free(buf);
	if (last_str[0] == '\0')
		return (free(last_str), NULL);
	return (last_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*last_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	last_str = read_until_nl_in_buf(fd, last_str);
	if (!last_str)
		return (NULL);
	line = get_nl_line(last_str);
	if (!line)
		return (free(last_str), NULL);
	last_str = new_last_str(last_str);
	return (line);
}

// # include <stdio.h>
// # include <unistd.h>

// int	main(void)
// {
// 	char	*line;
// 	int		fd = open("file.txt", O_RDONLY);

// 	while (1)
// 	{
// 		line = get_next_line(0);
// 		if (!line)
// 			break;
// 		printf(">>>%s", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }
