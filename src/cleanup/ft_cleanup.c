/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:56:24 by dlippelt          #+#    #+#             */
/*   Updated: 2025/06/19 12:10:28 by dlippelt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cleanup.h"

void	ft_cleanup_tex(t_tex *curr)
{
	t_tex	*next;

	while (curr)
	{
		next = curr->next;
		free(curr->tex_path);
		free(curr);
		curr = next;
	}
}

void	ft_cleanup_col(t_col *curr)
{
	t_col	*next;

	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
}

void	ft_cleanup_str_array(char **sa)
{
	size_t	i;

	if (!sa)
		return ;
	i = 0;
	while (sa[i])
	{
		free(sa[i]);
		sa[i] = NULL;
		i++;
	}
	free(sa);
	sa = NULL;
}

void	ft_cleanup(t_file *f)
{
	ft_cleanup_tex(f->tex);
	ft_cleanup_col(f->col);
	ft_cleanup_str_array(f->file);
	ft_cleanup_str_array(f->map.map);
}
