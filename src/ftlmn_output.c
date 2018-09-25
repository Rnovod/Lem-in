/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftlmn_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 17:07:47 by rnovodra          #+#    #+#             */
/*   Updated: 2018/08/16 17:07:48 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ftlmn_output(t_data *d, t_pars *p)
{
	const char	**tmp;

	p->output_size += OUTPUT_SIZE;
	tmp = (const char**)p->output;
	if (!(p->output = ft_arr_realloc(tmp, p->output_size)))
	{
		ft_arrfree(&tmp);
		ftlmn_error(d, p, 0);
	}
	ft_arrfree(&tmp);
}
