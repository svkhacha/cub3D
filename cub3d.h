/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabazyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:03:49 by sabazyan          #+#    #+#             */
/*   Updated: 2023/02/23 15:33:54 by sabazyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

# define WIDTH			2040
# define HEIGHT			1000

# define ROTATE_SPEED	0.15
# define MOVE_SPEED		0.2

# define RIGHT			124
# define LEFT			123
# define ESC			53
# define A				0
# define S				1
# define D				2
# define W				13

# define BUFFER_SIZE 10

typedef struct s_matrix {
	int		f1;
	int		f2;
	int		f3;
	int		c1;
	int		c2;
	int		c3;
	int		c_color;
	int		f_color;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*floor;
	char	*ceiling;
	char	**map;
}				t_matrix;

typedef struct s_index
{
	int	index_no;
	int	index_so;
	int	index_ea;
	int	index_we;
	int	index_c;
	int	index_f;
}				t_index;

typedef struct s_img
{
	void	*ptr;
	char	*img;
	int		bpp;
	int		width;
	int		height;
	int		size_line;
	int		endian;
}				t_img;

typedef struct s_game
{
	int		index;
	void	*mlx;
	void	*win;
	void	*no;
	void	*so;
	void	*ea;
	void	*we;
	int		x;
	int		y;
}				t_game;

typedef struct s_raycasting
{
	double	perpwalldist;
	double	deltadistx;
	double	deltadisty;
	int		lineheight;
	double	sidedistx;
	double	sidedisty;
	int		drawstart;
	double	camerax;
	double	raydiry;
	double	raydirx;
	int		drawend;
	double	planex;
	double	planey;
	int		stepx;
	int		stepy;
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	int		side;
	int		mapx;
	int		mapy;
	int		hit;
}				t_raycasting;

typedef struct s_data
{
	t_raycasting	*rcasting;
	t_index			*index;
	t_game			*game;
	t_img			*img;
	t_matrix		*args;
}				t_data;

//raycasting
void		init_structs(t_data *data);
void		init_win(t_data *data);
void		init_win_continue(t_data *data, int i, void *temp);
void		find_pos_player(t_data *data);
void		norm_init_win_2(t_data *data);
void		norm_init_win(t_data *data);
void		continue_init_win(t_data *data);
void		init_win(t_data *data);
void		draw_floor_and_celling(t_data *data, char *dest);
int			ft_texx(t_data *data, int n);
int			draw_walls(t_data *data, char *dest, char *dest_2, int texx);
void		norm_init_win_3(t_data *data);
void		rotate_right(t_data *data, double rotate);
void		move_left(t_data *data);
void		move_right(t_data *data);
void		move_up(t_data *data);
void		move_down(t_data *data);
int			key_manager(int key, t_data *data);
float		ft_abs(float num);
char		*get_correct_arg(char *ptr);
void		init_plane(t_data *data, double i, double j);
void		init_dir(t_data *data, double i, double j);
void		init_player_pos(t_data *data, int i, int j);
int			check_nwse(t_data *data);
void		ft_get_data_addr(t_data *data);
void		ft_mlx_xpm(t_data *data);
int			ft_close(int keycode, t_data *data);

//main.c
int			main(int ac, char **av);

//gnl.c
char		*loop(int fd, char *static_line);
char		*get_next_line(int fd);
char		**reading_file(int fd, int line_count);
int			reading_lines(int fd);
int			is_empty_str(char *line);

//errors.c
char		**check_arguments(int ac, char **av);
char		**check_arguments_2(char **av, int count);
int			check_new_lines(char **map);
int			check_extension(char *str);
int			check_other_chars(char **map, int first_i);

//split.c
int			letter_count(char *s, char c);
char		*create_word(char *s, int start_index, int len);
char		**ft_split(char *s, char c);

//utils.c
int			ft_strlen(char	*s);
char		*ft_substr(char *s, int start, int len);
char		*ft_strchr(char	*str, int c);
int			ft_atoi(const char	*str);
int			ft_strcmp(char	*s1, char	*s2);

//utils_2.c
char		*ft_strdup(char	*s1);
char		*ft_strjoin(char *s1, char *s2);
int			ft_isdigit(int c);
int			ft_isalpha(int c);

//parsing_map.c
int			check_walls(char **map, int first_i, int last_i);
int			check_walls_2(char **map, int i, int j);
int			malloc_counting(char *line);
char		*no_tab(char *line);
void		no_tab_2(int i, int j, char *new_line, char *line);

//parsing_map_2.c
int			check_full_map(char **map);
int			check_full_map_2(char **map, int i, int count, int count_2);
int			check_full_map_3(char **map, int i);
int			is_id(char *map_line, int j);
int			is_id_2(char *map_line, int j, char *new_line);

//parsing_map_3.c
int			check_player_count(char **map, int first_i);
int			check_player_count_2(char **map,
				int first_i, int n_count, int s_count);
int			check_textures(char *line);
int			check_textures_2(char *line, int i);
void		free_map(char **map);

//parsing_map_4.c
char		*create_line(char *map_line, int j);
int			check_line_f_c(char *line);
int			check_semi(char *line, int *i);
int			check_full_num(char *line, int *i, int *index);

//parsing_map_5.c
int			check_line_f_c_2(char *line);
int			check_line_f_c_3(char *temp, char **matrix);
int			is_id_3(char *map_line, int j);

//get_args.c
char		*get_arguments(char **map, char id, int num);
char		*path(char	*line, int num);
int			malloc_count(char *line);
char		**get_map(char	**map);
int			map_malloc_count(char **map);

//struct.c
t_matrix	*create_struct(char **map);
void		destroy_struct(t_matrix *args);

#endif
