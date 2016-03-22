/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 10:23:40 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/03/22 14:54:02 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//static void	parse_all_cmds(char *buffer, t_env *e)
//{
//
//}

void			parse_user(char *buffer, t_env *e)
{
	char	**cli;
	int		i;

	i = 0;
	cli = ft_strsplit(buffer, ' ');
	while (cli[i])
		i++;
	e->nbarg = i;
	if (i > 0)
	{
		e->cmd = ft_strdup(cli[0]);
		e->args = ft_array_str_cpy(cli, e->args);
		free(cli);
	}
	i = 0;
	if (e->path)
	{
		cli = ft_strsplit(e->path, ':');
		while (cli[i])
			i++;
		e->nbrpath = i;
		free(cli);
	}
}
