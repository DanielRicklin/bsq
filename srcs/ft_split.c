/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dricklin <dricklin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 20:10:24 by dricklin          #+#    #+#             */
/*   Updated: 2019/07/22 22:53:09 by dricklin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_bsq.h"

char	*ft_end_str(char *str, char *charset)
{
	int		i;
	int		j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (charset[j])
		{
			if (str[i] == charset[j])
				return (&str[i]);
			j++;
		}
		i++;
	}
	return (&str[i]);
}

char	*ft_copy(char *str, char *charset)
{
	int		i;
	char	*res;
	char	*clone_str;

	i = 0;
	clone_str = ft_end_str(str, charset);
	if (clone_str == str)
		return (0);
	res = malloc(clone_str - str + 1);
	if (res == 0)
		return (0);
	while (i < clone_str - str)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = 0;
	return (res);
}

int		ft_find_in_charset(char c, char *charset)
{
	int		i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		ft_size(char *str, char *charset)
{
	int		i;
	int		count;

	i = 0;
	if (ft_find_in_charset(str[0], charset))
		count = 0;
	else
		count = 1;
	while (str[i + 1])
	{
		if (ft_find_in_charset(str[i], charset) && !ft_find_in_charset(str[i + 1], charset))
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		size;
	int		i;
	char	*clone_str;

	clone_str = str;
	i = 0;
	if (str == 0)
		return (0);
	size = ft_size(str, charset);
	res = malloc((size + 1) * sizeof(char *));
	while (i < size)
	{
		if (ft_copy(clone_str, charset))
		{
			res[i] = ft_copy(clone_str, charset);
			clone_str = ft_end_str(clone_str, charset);
			i++;
		}
		while (ft_find_in_charset(*clone_str, charset))
			clone_str++;
	}
	res[i] = 0;
	return (res);
}