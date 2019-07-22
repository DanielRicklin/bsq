/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dricklin <dricklin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 17:12:43 by dricklin          #+#    #+#             */
/*   Updated: 2019/07/22 23:01:38 by dricklin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_bsq.h"

int		ft_skip_first_line(int fd)
{
	char	c;

	while(read(fd, &c, 1) != 0)
	{
		if(c == '\n')
			return (0);
	}
	return (0);
}

char	*ft_file_to_str(char *file)
{
	int		fd;
	char	c;
	char 	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(str) * (ft_strlen_file(file)));
	fd = open(file, O_RDONLY);
	ft_skip_first_line(fd);
	if (fd == -1)
		return (str);
	while(read(fd, &c, 1) != 0)
		str[i++] = c;
	str[i] = '\0';
	close(fd);
	return (str);
}

char	**ft_set_tab(char **tab, char *file)
{
	int		i;
	char	*str_file;
	
	i = 0;
	str_file = ft_file_to_str(file);
	tab = ft_split(str_file, "\n");
	while (tab[i])
		printf("%s\n", tab[i++]); // affichage du tableau
	return (tab);
}

int		ft_bsq(char *file)
{
	char	**tab;
	
	tab = malloc(sizeof(tab) * (ft_strlen_file(file))); //pas sur ça
	tab = ft_set_tab(tab, file);
	return (0);
}

int		main(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	if (argc > 1)
		ft_bsq(argv[1]);
	return (0);
}