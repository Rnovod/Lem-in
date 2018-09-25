/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 17:16:55 by rnovodra          #+#    #+#             */
/*   Updated: 2018/09/05 17:16:56 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H

# include "ft_printf.h"
# include "libft.h"
# include <errno.h>
# include <SDL2/SDL.h>
# include <SDL2/SDL_image.h>
# include <SDL2/SDL_ttf.h>

# define START 1
# define END 1 << 1
# define ANTEATER 1 << 2

# define FPS 30
# define HEIGHT 1200
# define WIDTH 1600
# define SPEED_ANT 30
# define APPROX(a, b) (a >= b - 1 && a <= b + 1)

# define KEY_LEFT 1
# define KEY_RIGHT 1 << 1
# define KEY_RETURN 1 << 2
# define KEY_EQUALS 1 << 3
# define KEY_MINUS 1 << 4
# define KEY_QUIT 1 << 5

typedef	struct	s_vlink
{
	struct s_vroom	*room;
	struct s_vlink	*next;
}				t_vlink;

typedef	struct	s_vroom
{
	char			*name;
	int				x;
	int				y;
	uint			anteater:1;
	t_vlink			*links;
	struct s_vroom	*next;
}				t_vroom;

typedef	struct	s_sdl_data
{
	SDL_Window		*win;
	SDL_Renderer	*rend;
	SDL_Texture		*background;
	SDL_Texture		*anteater;
	SDL_Texture		*ant[2];
	SDL_Texture		*ant_mov[4];
	TTF_Font		*font;
	SDL_Event		event;
}				t_sdl_data;

typedef struct	s_ant
{
	float			from_x;
	float			from_y;
	float			to_x;
	float			to_y;
	float			now_x;
	float			now_y;
	float			step_x;
	float			step_y;
	int				id;
	struct s_ant	*next;
}				t_ant;

typedef struct	s_moves
{
	t_ant			*ants;
	struct s_moves	*next;
	struct s_moves	*prev;
}				t_moves;

typedef	struct	s_vdata
{
	uint			fl;
	int				ants;
	uint			num_rooms;
	int				ant_start;
	int				ant_end;
	int				size;
	uint			keys;
	int				speed;
	const char		**file;
	t_vroom			*b;
	t_vroom			*st;
	t_vroom			*e;
	t_sdl_data		*sdl;
	t_moves			*begin_moves;
	const t_moves	*move;
}				t_vdata;

void			ftlmnv_error(t_vdata *d, int error);
void			ftlmnv_exit(t_vdata *d, int status);

void			ftlmnv_read_data(t_vdata *d);
int				ftlmnv_pars_ants(const char **file, int *index);
int				ftlmnv_pars_rooms(t_vdata *d, const char **file, int *index);
int				ftlmnv_room_format(t_vdata *d, const char *line);
int				ftlmnv_pars_links(t_vdata *d, const char **file, int *index);
int				ftlmnv_pars_moves(t_vdata *d, int index);

void			ftlmnv_init_sdl(t_vdata *d, t_sdl_data *s);
void			ftlmnv_create_backgrd(t_vdata *d, t_sdl_data *s);
void			ftlmnv_draw_farm(t_vdata *d, t_sdl_data *s);
void			ftlmnv_where_ants(t_vdata *d, t_sdl_data *s);
void			ftlmnv_ants_moving(t_vdata *d, t_sdl_data *s);
void			ftlmnv_ants_at_st_end(t_vdata *d, t_sdl_data *s);
void			ftlmnv_instr_spec(t_vdata *d, t_sdl_data *s);

const t_vroom	*ftlmnv_find_room(t_vdata *d, const char *line, int *len);

void			ftlmnv_key_down(t_vdata *d, t_sdl_data *s);
void			ftlmnv_key_up(t_vdata *d, t_sdl_data *s);

#endif
