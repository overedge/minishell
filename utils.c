/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <nahmed-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 00:05:43 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/03/23 14:45:07 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		error(char *filename, char *str, t_env *e)
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

char		**ft_array_str_cpy(char **src, char **dest)
{
	int		i;
	int		size;

	size = 0;
	i = 0;
	while (src[size])
		size++;
	dest = (char**)malloc(sizeof(char*) * (size + 1));
	while (i < size)
	{
		dest[i] = (char*)malloc(sizeof(char) * ft_strlen(src[i]) + 1);
		ft_strcpy(dest[i], src[i]);
		i++;
	}
	dest[i] = NULL;
	return (dest);
}

char		*get_home(char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], "HOME=", 5) != NULL)
			return (ft_strdup(ft_strsplit(env[i], '=')[1]));
		i++;
	}
	return (NULL);
}

char		**ft_unset_elem(char **src, char *key, int size)
{
	char	**dest;
	int		i;
	int		swp;

	i = 0;
	swp = 0;
	dest = (char**)malloc(sizeof(char *) * (size));
	while (src[i])
	{
		if (ft_strnstr(src[i], cjoin(key, "="), ft_strlen(key) + 1) == NULL)
		{
			dest[swp] = (char*)malloc(sizeof(char) * ft_strlen(src[i]) + 1);
			ft_strcpy(dest[swp], src[i]);
		}
		else
			swp--;
		i++;
		swp++;
	}
	dest[+swp] = NULL;
	free(src);
	return (dest);
}
