/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:11:01 by kbrener-          #+#    #+#             */
/*   Updated: 2024/04/17 14:40:13 by kbrener-         ###   ########.fr       */
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

typedef struct	s_mlx_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	*all_img;

}	t_mlx_data;

typedef struct	s_img
{
	void	*img_P_right;
	void	*img_P_left;
	void	*img_wall;
	void	*img_floor;
	void	*img_items;
	void	*img_exit;
}	t_img;


typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

/*main.c : */
void	ft_error(char *message);
void	ft_free_tab(char **tab);


/*check_map.c : fonctions permettant de verifier que le fichier fourni est
utilisable pour construire la map*/
t_map_data	*ft_check_map(char *argv);
int	ft_map_is_rect(int	fd, t_map_data *map);
int	ft_map_is_usable(t_map_data *map);
int	ft_a_way_exist(t_map_data *map);
void	ft_flood_map(char **map, int x, int y);

/*check_map_utils.c : fonctions complementaires de check_map*/
char	**ft_init_map_tab(char *argv, t_map_data *map);
t_map_data	*ft_init_map_data(void);
int	ft_count_elements(t_map_data *map, int i, int j);
int	ft_line_is_wall(char *line);
int	ft_file_is_ber(char *argv);

# endif
