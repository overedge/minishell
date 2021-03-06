/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <nahmed-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 19:03:33 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/03/23 15:55:24 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*get_env(char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH=", 5) != NULL)
			return (ft_strdup(ft_strsplit(env[i], '=')[1]));
		i++;
	}
	return ("");
}

static void	del_tab(char *buffer)
{
	int		i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\t')
			buffer[i] = ' ';
		i++;
	}
}

static void	no_quit(int sig)
{
	if (sig == 2)
	{
		ft_putchar('\n');
		ft_printf("$> ");
	}
}

int			main(int ac, char **argv, char **env)
{
	char	*buffer;
	t_env	e;

	argv++;
	ac = 0;
	ft_memset(&e, 0, sizeof(e));
	e.env = ft_array_str_cpy(env, e.env);
	signal(SIGINT, no_quit);
	while (42)
	{
		e.path = get_env(e.env);
		ft_printf("$> ");
		get_next_line(0, &buffer);
		del_tab(buffer);
		parse_all_cmds(buffer, &e);
		while (ac < e.nbcmd)
		{
			parse_user(e.cmds[ac], &e);
			(e.nbarg > 0 && is_bull(e.cmd, &e) == 1) ? cmd(&e) : 0;
			free(e.cmds[ac]);
			ac++;
		}
		ac = 0;
	}
	return (0);
}
