/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:15:47 by kbrener-          #+#    #+#             */
/*   Updated: 2024/04/23 14:56:37 by kbrener-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

# include "so_long.h"





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
		{
			argv++;
			if (argv[4])
				return (1);
			return (0);
		}
		argv++;
	}
	return (1);
}
