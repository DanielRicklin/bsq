/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dricklin <dricklin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 20:38:40 by dricklin          #+#    #+#             */
/*   Updated: 2019/07/22 22:43:46 by dricklin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_bsq.h"

int		ft_strlen_file(char *file)
{
	int		fd;
	char	c;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	ft_skip_first_line(fd);
	if (fd == -1)
		return (0);
	while(read(fd, &c, 1) != 0)
		i++;
	close(fd);
	return (i);
}