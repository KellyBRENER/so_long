/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:25:24 by kbrener-          #+#    #+#             */
/*   Updated: 2024/04/15 15:23:38 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_map(char *argv)
{
	int	fd;
	int	x;
	int	y;
	char	**map;

	if (ft_file_is_ber(argv) == 1)
		ft_error("wrong format for map file");
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_error("file cannot be open");
	if (ft_map_is_rect(fd, &x, &y) != 0)
	{
		close(fd);
		ft_error("map is not a rectangle");
	}
	close(fd);
	map = ft_init_tab(argv, x, y);
	if (!map)
		ft_error("error initialising map");
	if (ft_map_is_usable(map, x, y)!= 0)
	{
		ft_free_tab(map);
		ft_error("map is not usable");
	}
}

int	ft_file_is_ber(char *argv)
{
	while (*argv)
	{
		if (ft_strncmp(argv, ".ber", 4) == 0)
			return (0);
		argv++;
	}
	return (1);
}

int	ft_map_is_rect(int	fd, int *x, int *y)
{
	char	*str;

	*x = 0;
	*y = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break;
		if (*y == 0)
			*x = ft_strlen(str);
		else if (ft_strlen(str) != *x)//lignes de differentes tailles
			return (free(str), -1);
		*y++;
		free(str);
	}
	if (*y == 0 || *x == 0)
		return (-1);
	if (*y == *x)
		return (-1);
	return (0);
}

char	**ft_init_tab(char *argv, int x, int y)
{
	int	fd;
	char	**tab;
	int	i;

	i = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (NULL);
	tab = malloc(sizeof(char *) * (y + 1));
	if (!tab)
		return (close(fd), NULL);
	while (i < y)
	{
		tab[i] = get_next_line(fd);
		if (!tab[i])
			return (ft_free_tab(tab), close(fd), NULL);
		i++;
	}
	close(fd);
	tab[i] = '\0';
	return (tab);
}

int	ft_map_is_usable(char **map, int x, int y)
{
	int	exit;
	int	starting;
	int	items;

	ft_check_elements;
}

void	ft_check_elements(char **map, int *exit, int *starting, int *items)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	*exit = 0;
	*starting = 0;
	*items = 0;
	while (map[i])
	{
		while (map[i][j])
		{

		}
	}
}
