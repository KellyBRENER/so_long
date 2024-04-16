/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:25:24 by kbrener-          #+#    #+#             */
/*   Updated: 2024/04/16 15:18:58 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*verifie que
	- le fichier est au format .ber,
	- on peut l'ouvrir,
	- la map est rectangulaire
	- que sa compo respecte les prerequis du sujet*/
t_map_data	*ft_check_map(char *argv)
{
	int	fd;
	t_map_data	*map;

	map = ft_init_map_data();
	if (ft_file_is_ber(argv) == 1)
		ft_error("wrong format for map file");
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_error("file cannot be open");
	if (ft_map_is_rect(fd, map) != 0)
	{
		close(fd);
		ft_error("map is not a rectangle");
	}
	close(fd);
	map->tab = ft_init_map_tab(argv, map);
	if (!map->tab)
		ft_error("error initialising map");
	if (ft_map_is_usable(map) != 0)
	{
		ft_free_tab(map->tab);
		free(map);
		ft_error("map is not usable");
	}
	return (map);
}

/*verirfie que la map est un rectangle*/
int	ft_map_is_rect(int	fd, t_map_data *map)
{
	char	*str;

	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break;
		if (map->y == 0)
			map->x = ft_strlen(str);
		else if (ft_strlen(str) != map->x)//lignes de differentes tailles
			return (free(str), -1);
		map->y++;
		free(str);
	}
	if (map->y == 0 || map->x == 0)
		return (-1);
	if (map->y == map->x)
		return (-1);
	return (0);
}

/*verifie que la map est entouree de mur, qu'elle contient au moins un item
et qu'il n'y a qu'une seule sortie et position de depart */
int	ft_map_is_usable(t_map_data *map)
{
	int	i;

	i = 0;
	while (map->tab[i])
	{
		if ((i = 0 || (i == (map->y - 1)))
			&& ft_line_is_wall(map->tab[i++]) != 0)
			return (-1);
		while (i > 0 && (i < (map->y - 1)))
		{
			if (ft_count_elements(map, i, 0) != 0)
				return (-1);
			i++;
		}
	}
	if (map->C < 1 || map->E > 1 || map->P > 1 || ft_a_way_exist(map) != 0)
		return (-1);
	return (0);
}

/*verifie qu'un chemin existe pour collecter les items et rejoindre la sortie*/
int	ft_a_way_exist(t_map_data *map)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	ft_flood_map(map->tab, map->P_x, map->P_y);
	while (map->tab[i])
	{
		while (map->tab[i][j])
		{
			if (map->tab[i][j] == 'C' || map->tab[i][j] == 'P'
				|| map->tab[i][j] == 'E')
				return (-1);
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}

/*remplit toute la map accessible par des 'F' a partir de P*/
void	ft_flood_map(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'F')
		return;
	map[y][x] = 'F';
	ft_flood_map(map, y + 1, x);
	ft_flood_map(map, y - 1, x);
	ft_flood_map(map, y, x + 1);
	ft_flood_map(map, y, x - 1);
}
