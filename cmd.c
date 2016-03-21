/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 10:49:43 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/03/19 21:26:29 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd(t_env *e)
{
	char	**try;
	int		i;
	pid_t	father;
	char *binname;

	i = 0;
	try = ft_strsplit(e->path, ':');
	father = fork();
	if (father == 0)
	{
		while (i < e->nbrpath)
		{
			if (e->cmd[0] != '/' && e->cmd[0] != '.')
				binname = cjoin(try[i], cjoin("/", e->cmd));
			else
				binname = e->cmd;
			if (execve(binname, e->args, e->env) == -1)
				;
			else
			{
				e->error = 0;
				break ;
			}
			i++;
		}
		if (i == e->nbrpath)
			error(e->cmd, "minishell : command not found: ", e);
		exit(EXIT_SUCCESS);
	}
	else
		wait(NULL);
}
