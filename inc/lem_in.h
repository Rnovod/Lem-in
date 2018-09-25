/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 17:32:13 by rnovodra          #+#    #+#             */
/*   Updated: 2018/09/23 10:28:16 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# define OUTPUT_SIZE 1000

# define START 1
# define END 1 << 1
# define ANTEATER 1 << 2

# define LMN_INFO_WAYS 1
# define LMN_INFO_FARM 1 << 1
# define LMN_INFO_TRACE 1 << 2
# define LMN_INFO_LEAKS 1 << 3
# define LMN_NAME 1 << 4

# include "ft_printf.h"
# include "libft.h"
# include <stdio.h>
# include <errno.h>

typedef struct	s_links
{
	struct s_links	*next;
	struct s_room	*room;
	struct s_links	*prev;
}				t_links;

typedef struct	s_room
{
	char			*name;
	int				x;
	int				y;
	ssize_t			dis;
	ssize_t			size;
	uint8_t			visit:1;
	int				ant;
	t_links			*links;
	struct s_room	*next;
}				t_room;

typedef struct	s_ways
{
	t_links			*start;
	t_links			*end;
	int				len;
	struct s_ways	*next;
}				t_ways;

typedef struct	s_pars
{
	char			**output;
	int				output_size;
	int				i;
	char			*line;
	t_room			*ptr;
	int				flags;
}				t_pars;

typedef struct	s_data
{
	int				ants;
	t_room			*begin;
	t_room			*start;
	t_room			*end;
	t_ways			*ways;
	uint32_t		arg_fl;
	int				fd;
}				t_data;

int				ftlmn_mng_argv(t_data *d, char **av);
char			**ftlmn_read_farm(t_data *d);
void			ftlmn_output(t_data *d, t_pars *p);
int				ftlmn_ants(t_data *d, t_pars *p);
int				ftlmn_rooms(t_data *d, t_pars *p);
int				ftlmn_room_format(t_data *d, t_pars *p, const char *line);
void			ftlmn_command_room(t_data *d, t_pars *p, t_room *room);
void			ftlmn_get_command(t_data *d, t_pars *p);
void			ftlmn_get_comment(t_data *d, t_pars *p);
int				ftlmn_links(t_data *d, t_pars *p);

void			ftlmn_bfs(t_data *d);
void			ftlmn_print_all(t_data *d);
void			ftlmn_find_ways(t_data *d);
void			ftlmn_go_back(t_data *d, t_room *room);
void			ftlmn_put_ants(t_data *d);

void			ftlmn_error(t_data *d, t_pars *p, int error);
void			ftlmn_exit(t_data *d, int status);

#endif
