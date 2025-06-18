/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:56:24 by dlippelt          #+#    #+#             */
/*   Updated: 2025/06/18 15:53:40 by dlippelt         ###   ########.fr       */
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

void	ft_cleanup_file(char **file)
{
	size_t	line;

	if (!file)
		return ;
	line = 0;
	while (file[line])
	{
		free(file[line]);
		line++;
	}
	free(file);
}

void	ft_cleanup(t_file *f)
{
	ft_cleanup_tex(f->tex);
	ft_cleanup_col(f->col);
	ft_cleanup_file(f->file);
}
