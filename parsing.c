/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 10:23:40 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/03/15 12:06:41 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void parse_user(char *buffer, t_env *e)
{
	char	**cli;
	int		i;
	i = 0;
	cli = ft_strsplit(buffer , ' ');
	while (cli[i])
		i++;
	e->nbarg = i;
	if (i > 0)
	{
		e->cmd = ft_strdup(cli[0]);
		free(cli);
	}
	else if (i > 1)
	{
		e->cmd = ft_strdup(cli[0]);
		e->args = cli;
		free(cli);
	}
	//i = 0;
	//cli = ft_strsplit(e->path, ':');
//	while (cli[i])
//		i++;
//	free(cli);
	//e->nbrpath = i;
}
