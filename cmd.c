/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 10:49:43 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/03/21 18:33:16 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	child_handler(t_env *e, char **try)
{
	int		i;
	char	*binname;

	i = 0;
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

void	cmd(t_env *e)
{
	char	**try;
	pid_t	father;

	try = ft_strsplit(e->path, ':');
	father = fork();
	if (father == 0)
		child_handler(e, try);
	else if (father == -1)
		error("fork", "error with work ", e);
	else
		wait(NULL);
}
