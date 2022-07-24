/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 09:13:47 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/24 00:12:52 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

// # define WIDTH 1920
// # define HEIGHT 1080
# define WIDTH 1920
# define HEIGHT 1080

# include <libft.h>
# include <stdio.h>

typedef struct	s_vector {
	double	x;
	double	y;
}	t_vector;
typedef struct	s_v {
	int	x;
	int	y;
}	t_v;
typedef	struct s_darr {
	double	*arr;
	size_t	len;
} t_darr;

// typedef	struct	s_rays{
	
// 	// size_t		len;
// } t_rays;

typedef	struct	s_wall {
	t_vector	*wall;
	int		wall_top_pixel;
	int		wall_height;
	t_vector	*step;
	double		arr_dist[WIDTH];
	double		arr_angl[WIDTH];
	t_vector	rays[WIDTH];
	// array of boolean
	bool		vert[WIDTH];
	bool		horiz[WIDTH];
	size_t		len_arr;
	size_t		rys_len;
	// size_t	rys_len;
	
} t_wall;

typedef struct s_render {
	t_vector	*pvec;
	double		fov;
	int		turn_dir; // 0 neutral, -1 left, +1 right
	int		walk_dir; // 0 neutrak, -1 back, +1 front
	double		rot_angl;
	double		walk_spd;
	double		turn_spd;
	
	t_wall		*wall;
}	t_render;

// minilibx struct
typedef struct s_mlx {
	void	*mlx;
	void	*win;
	void	*img;
	int	*img_data;
	int		bpp;
	int		size_line;
	int		endian;
} t_mlx;

// Textures
typedef	struct s_textures {
	void			*img_s;
	void			*img_n;
	void			*img_e;
	void			*img_w;
	
	char			*north;
	char			*south;
	char			*east;
	char			*west;
	int		bpp;
	int		size_line;
	int		endian;
	bool 		found_h;
	bool 		found_v;
	int				*north_data;
	int				*south_data;
	int				*east_data;
	int				*west_data;
	int				*data_v;
	int				*data_h;
	int				*data;
	int				w;
	int				h;
	t_v		*north_vec;
} t_textures;

// Colors
typedef struct s_colors {
	int			ceiling;
	int			floor;
	int			clr;
} t_colors;


// The grand struct
typedef struct s_map {
	unsigned long		w;
	unsigned long		h;
	char			**map;
	t_colors		*clr;
	t_textures		*txtr;
	t_mlx			*mlx;
	t_render		*rndr;
}t_map;


bool	is_identifier(char *line);
bool	is_map(char *line);
#endif
