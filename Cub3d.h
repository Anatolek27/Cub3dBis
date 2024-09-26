/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunegel <akunegel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 02:02:24 by akunegel          #+#    #+#             */
/*   Updated: 2024/09/23 02:30:16 by akunegel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include "includes/gnl/get_next_line.h"
# include "mlx.h"

# define MOVE_SPEED 0.1
# define ROT_SPEED 0.05

typedef struct s_raycasting
{
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	double	fov;
	double	camerax;
	double	raydirx;
	double	raydiry;
	int		mapx;
	int		mapy;
	int		hit;
	int		side;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	int		lineheight;
	int		drawstart;
	int		drawend;
	int		clr;
	double	sidedistx;
	double	sidedisty;
	int		texx;
	int		texy;
	int		draw;
	int		stepx;
	int		stepy;
	double	wallx;
}				t_raycasting;

typedef struct s_player
{
	int		x;
	int		y;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	char	dir;
}				t_player;

typedef struct s_texture
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}				t_texture;

typedef struct s_i
{
	t_texture	no;
	t_texture	so;
	t_texture	we;
	t_texture	ea;
}				t_i;

typedef struct s_images
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_images;

typedef struct s_map
{
	char	**map;
	int		length;
	int		width;
}				t_map;

typedef struct s_paths
{
	char	*pfile;
	char	*ps;
	char	*pw;
	char	*pn;
	char	*pe;
	char	*pc;
	char	*pf;
}				t_paths;

typedef struct s_textures
{
	int	*rgbc;
	int	*rgbf;
	int	rgbc_hex;
	int	rgbf_hex;
	int	bc;
	int	bf;
}				t_textures;

typedef struct s_data
{
	int				bfile;
	int				bool;
	t_player		p;
	t_map			map;
	t_paths			paths;
	t_textures		t;
	t_raycasting	r;
	t_i				images;
	void			*mlx;
	void			*mlx_win;
	int				fd;
	char			**file;
	char			**tmp;
}				t_data;

int				ft_exit(t_data *data, char *err);
int				ft_strlen(char *str);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strcpy(char *dest, char *src);
void			parsing(t_data *data);
void			get_file(t_data *data);
void			*ft_calloc(size_t count, size_t size);
int				get_line_nb(t_data *data);
void			get_clean_file(t_data *data);
int				line_is_empty(char *line);
void			get_paths(t_data *data);
void			check_t_paths(t_data *data);
void			extract_xpm(t_data *data, char *pre, char *line, int i);
int				ft_atoi(const char *str);
int				*convert_rgb(char *d, t_data *data);
char			**ft_split(char const *s, char c);
void			check_c(t_data *data);
void			check_f(t_data *data);
unsigned int	rgb_to_hex(int *rgb);
int				check_valid_rgb(t_data *data);
void			check_rgb(t_data *data);
void			get_map(t_data *data);
int				get_longest_line(char **file);
int				get_map_lines(char **file, t_data *data);
void			check_map_chars(t_data *data, int i);
void			check_map_playable(t_data *data, int x, int y);
void			init_player(t_player *p);
void			start_mlx(t_data *data);
int				game_loop(t_data *data);
void			my_mlx_pixel_put(t_images *img, int x, int y, int rgb);
void			get_images(t_data *data);
int				handle_keypress(int keycode, t_data *data);
void			init_raycasting(t_data *data, int i);
void			get_ray_dist(t_data *data);
void			check_hit(t_data *data);
void			get_wall_dist(t_data *data);
void			select_texture(t_data *data, t_texture *texture);
void			free_tmp_int(char **tmp);
void			check_map_chars_extended(t_data *data, int i, int j);
void			cpy_tmp_file(t_data *data, int i, int j);

#endif
