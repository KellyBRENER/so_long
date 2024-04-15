/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:11:01 by kbrener-          #+#    #+#             */
/*   Updated: 2024/04/15 15:26:06 by kbrener-         ###   ########.fr       */
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

typedef struct	s_elem
{
	int	E;
	int	P;
	int	C;
	int	wall;
	int	
}


typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

# endif
