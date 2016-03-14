/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <nahmed-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 19:03:33 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/03/14 01:52:13 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <fcntl.h>
#include <stdio.h>

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
//	ft_memset(&e, 0, sizeof(e));
	e.path = get_env(env);
	int fd;
	int retour_gnl;
	fd = open("Makefile", O_RDONLY);
//	ft_printf("%d", fd);
	//perror("");
	while ((retour_gnl = get_next_line(fd, &buffer) != 6))
		ft_printf("le fd est de %d - %d : %s\n", fd ,retour_gnl, buffer);
	//while (42)
	//{
	//	ft_putstr("{debut}");
	//	e.error == 0 ? ft_printf("🚀  > ") : ft_printf("💥  > ");
	//	ft_putstr("{fin}");
	//	free(buffer);
	//}
	return (0);
}
