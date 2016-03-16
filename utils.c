/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <nahmed-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 00:05:43 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/03/16 20:17:42 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void error(char *filename, char *str, t_env *e)
{
	ft_putstr_fd(str, 2);
	e->error = 1;
	if (filename)
	{
		ft_putstr_fd(filename, 2);
		ft_putstr_fd(": ", 2);
		ft_putchar_fd('\n', 2);
	}
}

char **ft_array_str_cpy(char **src, char **dest)
{
	int		i;
	int		size;

	size = 0;
	i = 0;
	while (src[size])
		size++;
	dest = (char**)malloc(sizeof(char*) * size + 1);
	while (i < size)
	{
		dest[i] = (char*)malloc(sizeof(char) * ft_strlen(src[i]) + 1);
		ft_strcpy(dest[i], src[i]);
		i++;
	}
	dest[i] = NULL;
	return (dest);
}

char **ft_array_realloc(char **src, char *key, char *value)
{
	int		i;
	int		size;
	char	**dest;

	size = 0;
	i = 0;
	while (src[size])
		size++;
	dest = (char**)malloc(sizeof(char*) * size + 2);
	while (i < size)
	{
		dest[i] = (char*)malloc(sizeof(char) * ft_strlen(src[i]) + 1);
		ft_strcpy(dest[i], src[i]);
		i++;
	}
	if (value)
		dest[i] = ft_strjoin(ft_strjoin(key, "="), value);
	else
		dest[i] = ft_strjoin(key, "=");
	i++;
	dest[i] = NULL;
	return (dest);
}

char *cjoin(char *tmp, char *tmp2)
{
	char *str;

	str = ft_strjoin(tmp, tmp2);
//	if (tmp)
//		free(tmp);
//	if (tmp2)
//		free(tmp2);
	return (str);
}

char *get_home(char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if ((env[i] = ft_strnstr(env[i], "HOME=", 5)) != NULL)
			return (ft_strsplit(env[i], '=')[1]);
		i++;
	}
	return (NULL);
}

char *get_pwd(char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if ((env[i] = ft_strnstr(env[i], "PWD=", 4)) != NULL)
			return (ft_strsplit(env[i], '=')[1]);
		i++;
	}
	return (NULL);
}
