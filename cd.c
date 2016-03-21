/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <nahmed-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 18:59:28 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/03/19 19:18:50 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void basic_cd(t_env *e, char *pwd)
{
	char *freeme;

	freeme = malloc(sizeof(char) * 200);
	if (e->args[1][0] == '.' || e->args[1][0] == '/')
	{
		if (chdir(e->args[1]) == -1)
			error(e->args[1], "cd: no such file or directory ", e);
		else
		{
			getcwd(freeme, 200);
			e->env = ft_array_realloc(e->env, "OLDPWD", pwd);
			e->env = ft_array_realloc(e->env, "PWD", freeme);
		}
	}
	else
	{
		if (pwd)
		{
			if (chdir(cjoin(cjoin(pwd, "/"), e->args[1])) == -1)
				error(e->args[1], "cd: no such file or directory ", e);
			else
			{
				getcwd(freeme, 200);
				e->env = ft_array_realloc(e->env, "OLDPWD", pwd);
				e->env = ft_array_realloc(e->env, "PWD", freeme);
			}
			free(pwd);
		}
	}
}

void	cd(t_env *e)
{
	char *home;
	char *pwd;

	pwd = malloc(sizeof(char) * 200);
	pwd = getcwd(pwd, 200);
	if (e->nbarg == 1)
	{
		home = get_home(e->env);
		if (home)
		{
			if (chdir(home) == -1)
				error("home", "cd: no such file or directory ", e);
			else
			{
				e->env = ft_array_realloc(e->env, "OLDPWD", pwd);
				pwd = getcwd(pwd, 200);
				e->env = ft_array_realloc(e->env, "PWD", pwd);
			}
			free(home);
		}
		else
			error(NULL, "cd : No home directory.\n", e);
	}
	else if (e->nbarg == 2)
		basic_cd(e, pwd);
	else if (e->nbarg > 2)
		error(e->args[1], "cd: string not in pwd ", e);
}
