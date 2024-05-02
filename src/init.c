/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:00:11 by kbrener-          #+#    #+#             */
/*   Updated: 2024/05/02 09:51:02 by kbrener-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "so_long.h"

/*recupere les donnees du fichier.ber pour les mettre dans un tableau*/
char	**ft_init_map_tab(char *argv, t_map_data *map)
{
	int		fd;
	char	**tab;
	int		i;

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
		tab[i][map->x] = '\0';
		i++;
	}
	close(fd);
	tab[i] = NULL;
	return (tab);
}

/*malloc et initialise chaque variable de la structure t_map_data*/
t_map_data	*ft_init_map_data(t_mlx_data *mlx)
{
	t_map_data	*map;

	map = malloc(sizeof(t_map_data));
	if (!map)
		ft_error(mlx, "error initialising map_data");
	map->tab = NULL;
	map->x = 0;
	map->y = 0;
	map->e = 0;
	map->c = 0;
	map->p = 0;
	map->p_x = 0;
	map->p_y = 0;
	return (map);
}

int	ft_xpm_to_img(t_mlx_data *mlx, t_all_img *img)
{
	img->img_pr = mlx_xpm_file_to_image(mlx->mlx_ptr,
			img->path_pr, &img->width, &img->height);
	img->img_pl = mlx_xpm_file_to_image(mlx->mlx_ptr,
			img->path_pl, &img->width, &img->height);
	img->img_pu = mlx_xpm_file_to_image(mlx->mlx_ptr,
			img->path_pu, &img->width, &img->height);
	img->img_pd = mlx_xpm_file_to_image(mlx->mlx_ptr,
			img->path_pd, &img->width, &img->height);
	img->img_w = mlx_xpm_file_to_image(mlx->mlx_ptr,
			img->path_w, &img->width, &img->height);
	img->img_f = mlx_xpm_file_to_image(mlx->mlx_ptr,
			img->path_f, &img->width, &img->height);
	img->img_e = mlx_xpm_file_to_image(mlx->mlx_ptr,
			img->path_e, &img->width, &img->height);
	img->img_c = mlx_xpm_file_to_image(mlx->mlx_ptr,
			img->path_c, &img->width, &img->height);
	img->img_peno = mlx_xpm_file_to_image(mlx->mlx_ptr,
			img->path_peno, &img->width, &img->height);
	img->img_peok = mlx_xpm_file_to_image(mlx->mlx_ptr,
			img->path_peok, &img->width, &img->height);
	if (!img->img_peok || !img->img_pr || !img->img_peno || !img->img_c
		|| !img->img_e || !img->img_f || !img->img_w || !img->img_pl
		|| !img->img_pd || !img->img_pu)
		return (-1);
	return (0);
}

/*malloc et initialise toutes les images*/
t_all_img	*ft_init_all_img(t_mlx_data *mlx)
{
	t_all_img	*img;

	img = malloc(sizeof(t_all_img));
	if (!img)
		return (NULL);
	img->width = IMG_WIDTH;
	img->height = IMG_HEIGHT;
	img->path_pr = "./asset/pr.xpm";
	img->path_pl = "./asset/pl.xpm";
	img->path_pu = "./asset/pu.xpm";
	img->path_pd = "./asset/pd.xpm";
	img->path_w = "./asset/w.xpm";
	img->path_f = "./asset/f.xpm";
	img->path_e = "./asset/e.xpm";
	img->path_peno = "./asset/peno.xpm";
	img->path_peok = "./asset/peok.xpm";
	img->path_c = "./asset/c.xpm";
	if (ft_xpm_to_img(mlx, img) == -1)
		return (NULL);
	return (img);
}

void	ft_init_mlx(t_mlx_data *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		ft_error(mlx, "mlx initialisation failed");
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, (mlx->map->x * IMG_WIDTH),
			(mlx->map->y * IMG_HEIGHT), "AN ANGRY BABY");
	if (!mlx->win_ptr)
		ft_error(mlx, "window creation failed");
	mlx->all_img = ft_init_all_img(mlx);
	if (!mlx->all_img)
		ft_error(mlx, "t_all_img struct creation failed");
	mlx->move = 0;
}
