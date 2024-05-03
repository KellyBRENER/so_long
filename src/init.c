/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:00:11 by kbrener-          #+#    #+#             */
/*   Updated: 2024/05/03 14:54:51 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	*ft_init_img(t_mlx_data *mlx, char *name, int width, int height)
{
	void	*img;

	img = mlx_xpm_file_to_image(mlx->mlx_ptr, name, &width, &height);
	return (img);
}

/*malloc et initialise toutes les images*/
t_all_img	*ft_init_all_img(t_mlx_data *mlx)
{
	t_all_img	*img;
	int			len;

	img = malloc(sizeof(t_all_img));
	if (!img)
		return (NULL);
	len = IMG_HEIGHT;
	img->img_pr = ft_init_img(mlx, "./asset/pr.xpm", len, len);
	img->img_pl = ft_init_img(mlx, "./asset/pl.xpm", len, len);
	img->img_pu = ft_init_img(mlx, "./asset/pu.xpm", len, len);
	img->img_pd = ft_init_img(mlx, "./asset/pd.xpm", len, len);
	img->img_w = ft_init_img(mlx, "./asset/w.xpm", len, len);
	img->img_f = ft_init_img(mlx, "./asset/f.xpm", len, len);
	img->img_e = ft_init_img(mlx, "./asset/e.xpm", len, len);
	img->img_c = ft_init_img(mlx, "./asset/c.xpm", len, len);
	img->img_peno = ft_init_img(mlx, "./asset/peno.xpm", len, len);
	img->img_peok = ft_init_img(mlx, "./asset/peok.xpm", len, len);
	img->img_black = ft_init_img(mlx, "./asset/black.xpm", len, len);
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
