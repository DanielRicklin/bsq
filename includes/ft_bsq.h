/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dricklin <dricklin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 21:00:19 by dricklin          #+#    #+#             */
/*   Updated: 2019/07/22 22:53:12 by dricklin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_H
# define FT_BSQ_H

# include <stdio.h>

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
int		ft_strlen_file(char *file);
int		ft_skip_first_line(int fd);
char	**ft_split(char *str, char *charset);

#endif