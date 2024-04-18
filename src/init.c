/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:00:11 by kbrener-          #+#    #+#             */
/*   Updated: 2024/04/18 15:01:18 by kbrener-         ###   ########.fr       */
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

int	ft_xpm_to_img(t_mlx_data mlx, t_img img)
{
	img->img_PR = mlx_xpm_file_to_image(mlx->mlx_ptr,
		img->path_PR, &img->width, &img->height);
	if (!img->img_PR)
		return (-1);
	img->img_PL = mlx_xpm_file_to_image(mlx->mlx_ptr,
		img->path_PL, &img->width, &img->height);
	if (!img->img_PL)
		return (-1);
	img->img_W = mlx_xpm_file_to_image(mlx->mlx_ptr,
		img->path_W, &img->width, &img->height);
	if (!img->img_W)
		return (-1);
	img->img_F = mlx_xpm_file_to_image(mlx->mlx_ptr,
		img->path_F, &img->width, &img->height);
	if (!img->img_F)
		return (-1);
	img->img_E = mlx_xpm_file_to_image(mlx->mlx_ptr,
		img->path_E, &img->width, &img->height);
	if (!img->img_E)
		return (-1);
	img->img_C = mlx_xpm_file_to_image(mlx->mlx_ptr,
		img->path_C, &img->width, &img->height);
	if (!img->img_C)
		return (-1);
	return (0);
}

/*malloc et initialise toutes les images*/
t_img	*ft_init_all_img(t_mlx_data mlx)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!img)
		return (NULL);
	img->width = IMG_WIDTH;
	img->height = IMG_HEIGHT;
	img->path_PR = "./asset/player_right.xpm";
	img->path_PL = "./asset/player_left.xpm";
	img->path_W = "./asset/wall.xpm";
	img->path_F = "./asset/floor.xpm";
	img->path_E = "./asset/exit.xpm";
	img->path_C = "./asset/item.xpm";
	if (ft_xpm_to_img(mlx, img) == -1)
		return (NULL);
	return (img);
}


t_mlx_data	*ft_init_mlx(t_map_data *map)
{
	t_mlx_data	*mlx;

	mlx = malloc(sizeof(t_mlx_data));
	if (!mlx)
		return (NULL);
	mlx->mlx_ptr = mlx_init();//connection avec le serveur graphique
	if (!mlx->mlx_ptr)
		return (NULL);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, (map->x * IMG_HI), 1080, "Hello world!");
	if (!mlx->win_ptr)
	{
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
		return (NULL);
	}
	mlx->all_img = ft_init_all_img(mlx);
	if (!mlx->all_img)
	{
		mlx_destroy_display(mlx_ptr);
		mlx_destroy_window(mlx_ptr, win_ptr);
		free(mlx_ptr);
	}
	return (mlx);
}
