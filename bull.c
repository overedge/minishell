/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bull.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <nahmed-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 23:46:52 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/03/22 14:47:06 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_setenv(t_env *e)
{
	if (e->nbarg == 1)
		ft_env(e);
	else if (e->nbarg == 2)
		e->env = ft_array_realloc(e->env, e->args[1], NULL);
	else if (e->nbarg == 3)
		e->env = ft_array_realloc(e->env, e->args[1], e->args[2]);
	else
		error("setenv", "Too many arguments. ", e);
}

void	ft_unsetenv(t_env *e)
{
	int		i;

	i = 1;
	if (e->nbarg == 1)
		error("unsetenv", "Too few arguments. ", e);
	else
	{
		while (i < e->nbarg)
		{
			e->env = ft_array_unset(e->env, e->args[i]);
			i++;
		}
	}
}

void	ft_env(t_env *e)
{
	int		i;

	i = 0;
	while (e->env[i])
	{
		ft_printf("%s\n", e->env[i]);
		i++;
	}
}

void	ft_exit(t_env *e)
{
	if (e->nbarg == 1)
		exit(0);
	else if (e->nbarg == 2)
		exit(ft_atoi(e->args[1]));
	else
		error("exit", "Too many arguments. ", e);
}

int		is_bull(char *cmd, t_env *e)
{
	int		i;

	i = 0;
	if (ft_strcmp("cd", cmd) == 0)
		cd(e);
	else if (ft_strcmp("setenv", cmd) == 0)
		ft_setenv(e);
	else if (ft_strcmp("env", cmd) == 0)
		ft_env(e);
	else if (ft_strcmp("exit", cmd) == 0)
		ft_exit(e);
	else if (ft_strcmp("unsetenv", cmd) == 0)
		ft_unsetenv(e);
	else
		return (1);
	return (0);
}
