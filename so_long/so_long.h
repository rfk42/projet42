/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:13:28 by locherif          #+#    #+#             */
/*   Updated: 2024/07/30 15:26:21 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "Libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct s_pos
{
	int		ligne;
	int		colonne;
}			t_pos;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	char	**str;
	void	*imgs[5];
	int		last_exit;
	int		move_count;
}			t_vars;

typedef struct m_mlx
{
}			t_mlx;

int			how_much_lines(char *map);
int			check_file_format(char *map_name);
int			lines_length(int len, char *map);
void		field_string(char **file, char *map, int len);
int			is_closed(char **map, int len);
int			find_textures(char **str, int len);
int			rigth_textures(char **str, int len);
char		**tab_dup(char **src, int len);
t_pos		get_pos(char **str, int len);
void		find_path(char **str, int ligne, int colonne);
char		**call_parsing(char **av);
int			call_parsing_in_parsing(char *av);
void		free_strings(char **s1);
void		move_to_left(t_vars *vars);
int			check_exit(t_vars *vars);
void		find_player_position(t_vars *vars, int *i, int *j);
void		move_to_right(t_vars *vars);
void		move_up(t_vars *vars);
void		move_down(t_vars *vars);
int			close_window(t_vars *vars);
void		free_lib(t_vars *vars);
void		free_images(t_vars *vars);
void		free_window_and_display(t_vars *vars);
void		print_map(t_vars *vars);
int			c_est_pas_du_caca(char **str, int len);
int			valid_exit(char **str, int i, int j);
void		setup_hooks(t_vars *vars, char **str);
int			get_adress(t_vars *vars);
void		get_images(t_vars *vars, int j, int i);
int			win_heigth(t_vars *vars);
int			win_length(t_vars *vars);
int			key_pressed(int key, t_vars *vars);
void		free_tab(char **av);
#endif
