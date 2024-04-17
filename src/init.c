/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:45:10 by kbrener-          #+#    #+#             */
/*   Updated: 2024/04/17 14:52:11 by kbrener-         ###   ########.fr       */
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
		tab[i][map->x - 1] = '\0';
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
/*malloc et initialise toutes les images*/
t_img	*ft_init_all_img();
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!img)
		return (NULL);
}

t_mlx_data	*ft_init_mlx(void)
{
	t_mlx_data	*mlx;

	mlx = malloc(sizeof(t_mlx_data));
	if (!mlx)
		return (NULL);
	mlx->mlx_ptr = mlx_init();//connection avec le serveur graphique
	if (!mlx->mlx_ptr)
		return (NULL);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, 1920, 1080, "Hello world!");
	if (!mlx->win_ptr)
	{
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
		return (NULL);
	}
	mlx->all_img = ft_init_all_img();
	if (!mlx->all_img)
	{
		mlx_destroy_display(mlx_ptr);
		mlx_destroy_window(mlx_ptr, win_ptr);
		free(mlx_ptr);
	}
	return (mlx);
}
