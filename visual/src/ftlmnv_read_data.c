/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftlmnv_read_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 13:30:09 by rnovodra          #+#    #+#             */
/*   Updated: 2018/09/06 13:30:10 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

inline static void	ftlmnv_print_farm(t_vdata *d)
{
	int			i;
	const char	**file = d->file;

	i = 0;
	while (file[i] && file[i][0] != 'L')
		ft_putendl(file[i++]);
	ft_putchar('\n');
	while (file[i])
		ft_putendl(file[i++]);
}

inline static int	ftlmnv_pars_data(t_vdata *d, const char **file)
{
	int	index;

	if ((d->ants = ftlmnv_pars_ants(file, &index)) <= 0)
		ftlmnv_error(d, 3);
	if (!(d->b = (t_vroom*)ft_memalloc(sizeof(t_vroom))))
		ftlmnv_error(d, 1);
	if ((ftlmnv_pars_rooms(d, file, &index)) < 0)
		ftlmnv_error(d, 4);
	if (d->num_rooms > 30)
		ftlmnv_error(d, 8);
	if ((ftlmnv_pars_links(d, file, &index)) < 0)
		ftlmnv_error(d, 5);
	if (ftlmnv_pars_moves(d, index) < 0)
		ftlmnv_error(d, 6);
	ftlmnv_print_farm(d);
	return (0);
}

void				ftlmnv_read_data(t_vdata *d)
{
	char		*read_data;
	const char	**file;

	if (!(read_data = ft_read_file(0)))
		ftlmnv_error(d, 1);
	if (!(file = (const char**)ft_strsplit(read_data, '\n')))
		ftlmnv_error(d, 1);
	free(read_data);
	d->file = file;
	if (!*file)
		ftlmnv_error(d, 7);
	if (ft_strncmp(*file, "ERROR", 5) && ft_strncmp(*file, "Error", 5))
	{
		if (ftlmnv_pars_data(d, file) == 0)
			return ;
	}
	ftlmnv_error(d, 2);
}
