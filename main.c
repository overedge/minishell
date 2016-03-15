/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <nahmed-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 19:03:33 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/03/15 12:01:06 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *get_env(char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH=", 5) != NULL)
			return (env[i]);
		i++;
	}
	return (NULL);
}

int main(int ac, char **argv, char **env)
{
	char *buffer;
	t_env e;
	ac++;
	argv++;
	ft_memset(&e, 0, sizeof(e));
	e.path = ft_strdup(get_env(env));
	while (42)
	{
		e.error == 0 ? ft_printf("🚀  > ") : ft_printf("💥  > ");
		ft_memset(&e, 0, sizeof(e));
		get_next_line(0, &buffer);
		parse_user(buffer, &e);
		if (e.nbarg > 0)
			cmd(&e, env);
		free(buffer);
	}
	return (0);
}
