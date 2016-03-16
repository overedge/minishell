/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bull.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <nahmed-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 23:46:52 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/03/16 01:01:03 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cd(t_env *e, char **env)
{

}

void	ft_setenv(t_env *e, char **env)
{

}

void	ft_unsetenv(t_env *e, char **env)
{

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
	{"setenv", &ft_setenv}, \
	{"unsetenv", &ft_unsetenv}, \
	{"env", &ft_env}, \
	{"exit", &ft_exit}};
	
	while (i <= 4)
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
