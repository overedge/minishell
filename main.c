/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <nahmed-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 19:03:33 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/03/16 01:01:04 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void reconstruct_env(t_env *e, char **env)
{
	e->args = NULL;
	e->path = get_env(env);
	e->nbarg = 0;
	e->cmd = NULL;
	e->nbrpath = 0;
}

char *get_env(char **env)
{
	int		i;
	i = 0;

	while (env[i])
	{
		if ((env[i] = ft_strnstr(env[i], "PATH=", 5)) != NULL)
			return (ft_strsplit(env[i], '=')[1]);
		i++;
	}
	return (NULL);
}

static int get_env_size(char **env)
{
	int		i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}

int main(int ac, char **argv, char **env)
{
	char	*buffer;
	t_env	e;
	char	**environ;

	ft_memset(&e, 0, sizeof(e));
	//e.path = get_env(env);
	//e.args = NULL;
	environ = ft_array_str_cpy(env, environ, get_env_size(env));
	e.path = get_env(env);
	while (42)
	{
		e.error == 0 ? ft_printf("🚀  > ") : ft_printf("💥  > ");
		get_next_line(0, &buffer);
		parse_user(buffer, &e);
		if (e.nbarg > 0 && is_bull(e.cmd, &e, environ) == 1)
			cmd(&e, environ);
		free(buffer);
	//	reconstruct_env(&e, env);
	}
	return (0);
}
