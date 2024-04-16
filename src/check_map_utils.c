/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:15:47 by kbrener-          #+#    #+#             */
/*   Updated: 2024/04/16 16:12:27 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

/*recupere les donnees du fichier.ber pour les mettre dans un tableau*/
char	**ft_init_map_tab(char *argv, t_map_data *map)
{
	int	fd;
	char	**tab;
	int	i;

	i = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (NULL);
	tab = malloc(sizeof(char *) * (map->y + 1));
	if (!tab)
		return (close(fd), NULL);
	while (i < map->y)
	{
		tab[i] = get_next_line(fd);
		if (!tab[i])
			return (ft_free_tab(tab), close(fd), NULL);
		i++;
	}
	close(fd);
	tab[i] = NULL;
	return (tab);
}

/*malloc et initialise chaque variable de la structure t_map_data*/
t_map_data	*ft_init_map_data(void)
{
	t_map_data	*map;

	map = malloc(sizeof(t_map_data));
	if (!map)
		ft_error("error initialising map_data");
	map->tab = NULL;
	map->x = 0;
	map->y = 0;
	map->E = 0;
	map->C = 0;
	map->P = 0;
	map->P_x = 0;
	map->P_y = 0;
	return (map);
}

/*compte le nombre d'items, de position de depart et de sortie et verifie
que la 1ere et derniere position soit un mur*/
int	ft_count_elements(t_map_data *map, int i, int j)
{
	while (map->tab[i][j])
	{
		if ((i == 0 || (i == (map->x - 1))) && map->tab[i][j] != '1')//contour n'est pas mur
			return (-1);
		else if (map->tab[i][j] == 'E')
			map->E++;
		else if (map->tab[i][j] == 'P' && map->P == 0)
		{
			map->P++;
			map->P_x = j;
			map->P_y = i;
		}
		else if (map->tab[i][j] == 'C')
			map->C++;
		else if (map->tab[i][j] != 'E' && map->tab[i][j] != 'P'
			&& map->tab[i][j] != 'C' && map->tab[i][j] != '1'
			&& map->tab[i][j] != '0')//symbole non valable
			return (-1);
		j++;
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
