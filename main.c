/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayusa <ayusa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 20:45:21 by ayusa             #+#    #+#             */
/*   Updated: 2025/07/29 19:13:31 by ayusa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_so_long	dt;

	dt.fd = -1;
	dt.map = NULL;
	if (ac != 2)
		error_exit(&dt, "Usage: ./so_long <map_file.ber>");
	dt.file = av[1];
	read_map(&dt);



	size_t i = 0;
	while (dt.map[i])
	{
		size_t j = 0;
		while (dt.map[i][j])
		{
			//printf("i: %zu, j: %zu\n", i, j);
			printf("%c", dt.map[i][j++]);

		}
		i++;
	}

	so_long(&dt);





	free_map(dt.map);
}
