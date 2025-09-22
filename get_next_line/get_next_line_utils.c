/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayusa <ayusa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 13:11:56 by ayusa             #+#    #+#             */
/*   Updated: 2025/07/11 21:09:18 by ayusa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*to_new_last_str(char *last_str, char *buf)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	if (!buf)
		return (free(last_str), NULL);
	if (!last_str)
	{
		last_str = (char *)malloc(1 * sizeof(char));
		if (!last_str)
			return (NULL);
		last_str[0] = '\0';
	}
	ptr = malloc(sizeof(char) * (ft_strlen(last_str) + ft_strlen(buf) + 1));
	if (ptr == NULL)
		return (free(last_str), NULL);
	i = -1;
	if (last_str)
		while (last_str[++i] != '\0')
			ptr[i] = last_str[i];
	j = 0;
	while (buf[j] != '\0')
		ptr[i++] = buf[j++];
	ptr[i] = '\0';
	return (free(last_str), ptr);
}
