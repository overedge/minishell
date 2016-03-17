/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <nahmed-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 19:03:33 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/03/17 00:10:09 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *get_env(char **env)
{
	int		i;
	char	**freme;
	char	**andme;

	i = 0;
	while (env[i])
	{
		if ((env[i] = ft_strnstr(env[i], "PATH=", 5)) != NULL)
			return (ft_strdup(ft_strsplit(env[i], '=')[1]));
		i++;
	}
	return (NULL);
}

int main(int ac, char **argv, char **env)
{
	char	*buffer;
	t_env	e;

	ft_memset(&e, 0, sizeof(e));
	e.env = ft_array_str_cpy(env, e.env);
	while (42)
	{
		e.path = get_env(e.env);
		e.error == 0 ? ft_printf("🚀  > ") : ft_printf("💥  > ");
		get_next_line(0, &buffer);
		parse_user(buffer, &e);
		if (e.nbarg > 0 && is_bull(e.cmd, &e) == 1)
			cmd(&e);
		free(buffer);
	}
	return (0);
}
