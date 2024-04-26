/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:11:01 by kbrener-          #+#    #+#             */
/*   Updated: 2024/04/26 12:00:15 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SO_LONG_H

#define SO_LONG_H

#include "../mlx/mlx.h"
#include <stdlib.h>
#include <unistd.h>
#include "../mlx/mlx_int.h"
# include "../libft/libft/libft.h"
# include "../libft/gnl/get_next_line.h"
# include "../libft/printf/ft_printf.h"
# include <X11/keysym.h>
# include <X11/X.h>

#define IMG_WIDTH 75
#define IMG_HEIGHT 75

typedef struct	s_map_data
{
	char	**tab;
	int	x;
	int	y;
	int	E;
	int	P;
	int	C;
	int	P_x;
	int	P_y;
}	t_map_data;

typedef struct	s_all_img
{
	char	*path_PR;
	char	*path_PL;
	char	*path_W;
	char	*path_F;
	char	*path_E;
	char	*path_C;
	void	*img_PR;
	void	*img_PL;
	void	*img_W;
	void	*img_F;
	void	*img_C;
	void	*img_E;
	int		height;
	int		width;
}	t_all_img;

typedef struct	s_mlx_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_all_img	*all_img;
	t_map_data	*map;
	int	move;

}	t_mlx_data;

/*clean_error.c : */
void	ft_error(t_mlx_data *mlx, char *message);
void	ft_free_map(t_mlx_data *mlx);
void	ft_clean_all(t_mlx_data *mlx);
void	ft_free_tab(char **tab);
void	ft_img_to_window(t_mlx_data *mlx, void *img, int x, int y);
void	ft_print_map(t_mlx_data *mlx);
int	ft_exit(void *mlx);

/*check_map.c : fonctions permettant de verifier que le fichier fourni est
utilisable pour construire la map*/
void	ft_check_map(t_mlx_data *mlx, char *argv);
int	ft_map_is_rect(int	fd, t_map_data *map);
int	ft_map_is_usable(t_map_data *map);
int	ft_a_way_exist(t_map_data *map);
void	ft_flood_map(char **map, int x, int y);

/*check_map_utils.c : fonctions complementaires de check_map*/
int	ft_count_elements(t_map_data *map, int i, int j);
int	ft_line_is_wall(char *line);
int	ft_file_is_ber(char *argv);

/*init.c : fonctions qui initialisent structures et tableaux*/
char	**ft_init_map_tab(char *argv, t_map_data *map);
t_map_data	*ft_init_map_data(t_mlx_data *mlx);
int	ft_xpm_to_img(t_mlx_data *mlx, t_all_img *img);
t_all_img	*ft_init_all_img(t_mlx_data *mlx);
void	ft_init_mlx(t_mlx_data *mlx);

/*keypress.c : gere les interactions entre clavier/souris et map*/
int	ft_move(int keysym, t_mlx_data *mlx);
void	ft_up(t_mlx_data *mlx);
void	ft_print_move(t_mlx_data *mlx, int dir);



# endif
