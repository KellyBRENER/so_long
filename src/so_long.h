/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:11:01 by kbrener-          #+#    #+#             */
/*   Updated: 2024/04/26 15:19:37 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include "../mlx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include "../mlx/mlx_int.h"
# include "../libft/libft/libft.h"
# include "../libft/gnl/get_next_line.h"
# include "../libft/printf/ft_printf.h"
# include <X11/keysym.h>
# include <X11/X.h>

# define IMG_WIDTH 75
# define IMG_HEIGHT 75

typedef struct s_map_data
{
	char	**tab;
	int		x;
	int		y;
	int		e;
	int		p;
	int		c;
	int		p_x;
	int		p_y;
}	t_map_data;

typedef struct s_all_img
{
	char	*path_pr;
	char	*path_pl;
	char	*path_w;
	char	*path_f;
	char	*path_e;
	char	*path_c;
	void	*img_pr;
	void	*img_pl;
	void	*img_w;
	void	*img_f;
	void	*img_c;
	void	*img_e;
	int		height;
	int		width;
}	t_all_img;

typedef struct s_mlx_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_all_img	*all_img;
	t_map_data	*map;
	int			move;

}	t_mlx_data;

/*so_long : contient le main et les fonctions de sortie*/
int			ft_exit(void *mlx);
void		ft_error(t_mlx_data *mlx, char *message);

/*clean.c : */
void		ft_free_map(t_mlx_data *mlx);
void		ft_clean_all(t_mlx_data *mlx);
void		ft_free_tab(char **tab);

/*print.c : fonctions permettant d'afficher la map*/
void		ft_img_to_window(t_mlx_data *mlx, void *img, int x, int y);
void		ft_print_map(t_mlx_data *mlx);
void		ft_print_move(t_mlx_data *mlx, int dir);

/*check_map.c : fonctions permettant de verifier que le fichier fourni est
utilisable pour construire la map*/
void		ft_check_map(t_mlx_data *mlx, char *argv);
int			ft_map_is_rect(int fd, t_map_data *map);
int			ft_map_is_usable(t_map_data *map);
int			ft_a_way_exist(t_map_data *map);
void		ft_flood_map(char **map, int x, int y);

/*check_map_utils.c : fonctions complementaires de check_map*/
int			ft_count_elements(t_map_data *map, int i, int j);
int			ft_line_is_wall(char *line);
int			ft_file_is_ber(char *argv);

/*init.c : fonctions qui initialisent structures et tableaux*/
char		**ft_init_map_tab(char *argv, t_map_data *map);
t_map_data	*ft_init_map_data(t_mlx_data *mlx);
int			ft_xpm_to_img(t_mlx_data *mlx, t_all_img *img);
t_all_img	*ft_init_all_img(t_mlx_data *mlx);
void		ft_init_mlx(t_mlx_data *mlx);

/*keypress.c : gere les interactions entre clavier/souris et map*/
int			ft_move(int keysym, t_mlx_data *mlx);
void		ft_up(t_mlx_data *mlx);
void		ft_down(t_mlx_data *mlx);
void		ft_left(t_mlx_data *mlx);
void		ft_right(t_mlx_data *mlx);

#endif
