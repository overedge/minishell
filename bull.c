/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bull.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <nahmed-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 23:46:52 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/03/16 19:00:47 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_setenv(t_env *e, char **env)
{
	ft_printf("Je suis la commande : %s et jai %d args\n", e->cmd, e->nbarg - 1);
}

void	ft_unsetenv(t_env *e, char **env)
{
	ft_printf("Je suis la commande : %s et jai %d args\n", e->cmd, e->nbarg - 1);
}

void	ft_env(t_env *e, char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		ft_printf("%s\n", env[i]);
		i++;
	}
}

void	ft_exit(t_env *e, char **env)
{
	exit(EXIT_SUCCESS);
}

int is_bull(char *cmd, t_env *e, char **env)
{
	int		i;

	i = 0;
	t_bull ptr_bull[5] = {{"cd", &cd}, \
	{"exit", &ft_exit}, \
	{"setenv", &ft_setenv}, \
	{"unsetenv", &ft_unsetenv}, \
	{"env", &ft_env}};
	
	while (i < 5)
	{
		if (ft_strcmp(ptr_bull[i].code, cmd) == 0)
		{
			ptr_bull[i].f(e, env);
			e->error = 0;
			return (0);
		}
		i++;
	}
	return (1);
}
