/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <nahmed-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 18:59:28 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/03/16 20:00:18 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void basic_cd(t_env *e, char **env, char *pwd)
{
	if (pwd)
		ft_printf("%s\n", chdir(cjoin(cjoin(pwd, "/"), e->args[1])));
	if (e->args[1][0] == '.' || e->args[1][0] == '/')
	{
		if (chdir(e->args[1]) == -1)
			error(e->args[1], "cd: no such file or directory ", e);
	}
	else
	{
		if (pwd)
		{
			if (chdir(cjoin(cjoin(pwd, "/"), e->args[1])) == -1)
				error(e->args[1], "cd: no such file or directory ", e);
		}
	}
}

void	cd(t_env *e, char **stock)
{
	char *home;
	char *pwd;

	pwd = get_pwd(stock);
	//home = get_home(stock);
	if (e->nbarg == 1)
	{
		if (home)
		{
			if (chdir(home) == -1)
				error("home", "cd: no such file or directory ", e);
		}
		else
			error(NULL, "cd : No home directory.\n", e);
	}
	else if (e->nbarg == 2)
		basic_cd(e, stock, pwd);
	else if (e->nbarg > 2)
		error(e->args[1], "cd: string not in pwd ", e);
	//free(home);
}
