/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayusa <ayusa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 18:56:09 by ayusa             #+#    #+#             */
/*   Updated: 2025/07/19 18:11:25 by ayusa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
		free(map[i++]);
	free(map);
}

void	error_exit(t_so_long *dt, char *msg)
{
	int	len;

	if (dt->fd >= 0)
		close(dt->fd);

	if (dt->map)
		free_map(dt->map);

	len = ft_strlen(msg);
	write(2, "Error\n", 6);
	write(2, msg, len);
	write(2, "\n", 1);
	exit(1);
}