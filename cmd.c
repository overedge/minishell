/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 10:49:43 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/03/15 19:29:51 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd(t_env *e, char **env)
{
	//	int		i;
	//
	//	i = 1;
	//	ft_printf("Il y a %d path differnt\n", e->nbrpath);
	//	ft_printf("Il y a %d arguments differnt\n", e->nbarg);
	//	ft_printf("La commande taper est %s\n", e->cmd);
	//	while (i <= e->nbarg - 1)
	//	{
	//		ft_printf("Les argumennts sont %s\n", e->args[i]);
	//		i++;
	//	}
	char	**try;
	int		i;
	pid_t	father;

	i = 0;
	try = ft_strsplit(e->path, ':');
	father = fork();
	if (father == 0)
	{
		while (i < e->nbrpath)
		{
			if (execve(cjoin(try[i], cjoin("/", e->cmd)), e->args, env) == -1)
				;
			else
			{
				e->error = 0;
				break ;
			}
			i++;
		}
	}
	if (i == e->nbrpath)
		error(e->cmd, "minishell : command not found: ", e);
}
