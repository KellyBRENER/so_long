/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:25:24 by kbrener-          #+#    #+#             */
/*   Updated: 2024/04/16 11:49:21 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*verifie que
	- le fichier est au format .ber,
	- on peut l'ouvrir,
	- la map est rectangulaire
	- que sa compo respecte les prerequis du sujet*/
void	ft_check_map(char *argv, char ***map)
{
	int	fd;
	int	x;
	int	y;

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
	*map = ft_init_tab(argv, x, y);
	if (!*map)
		ft_error("error initialising map");
	if (ft_map_is_usable(*map, x, y)!= 0)
	{
		ft_free_tab(*map);
		ft_error("map is not usable");
	}
}

/*verifie que le nom de fichier fini par .ber*/
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

/*verirfie que la map est un rectangle*/
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

/*recupere les donnees du fichier.ber pour les mettre dans un tableau*/
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

t_elem	*ft_init_elem(void)
{
	t_elem	*elem;

	elem = malloc(sizeof(t_elem));
	if (!elem)
		return (NULL);
	elem->E = 0;
	elem->C = 0;
	elem->P = 0;
	elem->P_x = 0;
	elem->P_y = 0;
}

/*verifie que la map est entouree de mur, qu'elle contient au moins un item
et qu'il n'y a qu'une seule sortie et position de depart */
int	ft_map_is_usable(char **map, int x, int y)
{
	int	i;
	t_elem	*elem;

	i = 0;
	elem = ft_init_elem();
	if (!elem)
		return (-1);
	while (map[i])
	{
		if ((i = 0 || (i == (y - 1))) && ft_line_is_wall(map[i++]) != 0)
			return (free(elem), -1);
		while (i > 0 && (i < (y - 1)))
		{
			if (ft_count_elements(map[i], elem, x) != 0)
				return (free(elem), -1);
			if (elem->P_x != 0 && elem->P_y == 0)
				elem->P_y = i;
			i++;
		}
	}
	if (elem->C < 1 || ft_a_way_exist(map, x, y, elem) != 0)
		return (free(elem), -1);
	return (free(elem), 0);
}

/*compte le nombre d'items, de position de depart et de sortie et verifie
que la 1ere et derniere position est un mur*/
int	ft_count_elements(char *map, t_elem *elem, int x)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if ((i == 0 || (i == (x - 1))) && map[i] != '1')//contour n'est pas mur
			return (-1);
		else if (map[i] == 'E')
		{
			if (elem->E == 1)//plus d'une sortie
				return (-1);
			elem->E++;
		}
		else if (map[i] == 'P')
		{
			if (elem->P == 1)//plus d'une position de depart
				return (-1);
			elem->P++;
			elem->P_x = i;
		}
		else if (map[i] == 'C')
			elem->C++;
		else if (map[i] != 'E' && map[i] != 'P' && map[i] != 'C' &&
			map[i] != '1' && map[i] != '0')//symbole non valable
			return (-1);
		i++;
	}
	return (0);
}

/*verifie que la ligne n'est composee que de mur*/
int	ft_line_is_wall(char *line)
{
	int	i;

	i = 0;
	while(line[i])
	{
		if (line[i] != '1')
			return (-1);
		i++;
	}
	return (0);
}

/*verifie qu'un chemin existe pour collecter les items et rejoindre la sortie*/
int	ft_a_way_exist(char **map, int x, int y, t_elem *elem)
{
	int	i;
	int	j;

	i = elem->P_y;
	j = elem->P_x;
	if (ft_wall_everyw(map, i, j) == 0)
		return (-1);
	while (i < (y - 1))
	{
		while (j < (x - 1) && elem->C > 0)
		{
			ft_count_dir_usable(map, i, j)
			if (map[i][j + 1] == '1')
			{
				if (map[i][j - 1] == '1')
			}
			if (map[i][j] == 'C')
				elem->C--;

		}
	}
}

/*renvoie 0 si toutes les cases autour de map[i][j] sont des murs*/
int	ft_wall_everyw(char **map, int i, int j)
{
	if (map[i - 1][j] == '1' && map[i + 1][j] == '1' && map[i][j - 1] == '1'
		&& map[i][j + 1] == 1)
			return (0);
	return (1);
}
