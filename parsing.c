/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 10:23:40 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/03/23 15:53:15 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		parse_buffer(char *buffer, t_env *e)
{
	int		i;

	e->cmds = ft_strsplit(buffer, ';');
	i = 0;
	while (e->cmds[i])
		i++;
	e->nbcmd = i;
}

void			parse_all_cmds(char *buffer, t_env *e)
{
	int		i;
	int		selector;

	i = 0;
	selector = 0;
	while (buffer[i])
	{
		if (buffer[i] == ';' && buffer[i + 1])
			selector++;
		i++;
	}
	if (selector == 0)
	{
		e->nbcmd = 1;
		e->cmds = malloc(sizeof(char *) * 2);
		e->cmds[0] = buffer;
		e->cmds[1] = NULL;
	}
	else
		parse_buffer(buffer, e);
}

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
