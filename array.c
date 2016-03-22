/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 14:40:13 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/03/22 23:36:37 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**edit_key(char **src, char *key, char *value)
{
	int		i;
	int		size;
	char	**dest;

	size = 0;
	i = 0;
	while (src[size])
		size++;
	dest = (char**)malloc(sizeof(char*) * (size + 1));
	while (src[i])
	{
		ft_printf("life : %s\n", src[i]);
		if (ft_strnstr(src[i], cjoin(key, "="), ft_strlen(key) + 1) == NULL)
		{
			dest[i] = (char*)malloc(sizeof(char) * ft_strlen(src[i]) + 1);
			ft_strcpy(dest[i], src[i]);
		}
		else
			dest[i] = ft_strjoin(ft_strjoin(key, "="), value);
		i++;
	}
	ft_printf("FINISH !!!!!!!!!!!!!!!\n");
	dest[i] = NULL;
	free(src);
	return (dest);
}

char		*cjoin(char *tmp, char *tmp2)
{
	char *str;

	str = ft_strjoin(tmp, tmp2);
	return (str);
}

static int	key_exist(char **src, char *key)
{
	int		i;

	i = 0;
	while (src[i])
	{
		if (ft_strnstr(src[i], cjoin(key, "="), ft_strlen(key) + 1) != NULL)
			return (1);
		i++;
	}
	return (0);
}

char		**ft_array_unset(char **src, char *key)
{
	char	**dest;
	int		size;
	int		i;
	int		swp;

	swp = 0;
	size = 0;
	i = 0;
	if (key_exist(src, key) == 1)
	{
		while (src[size])
			size++;
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
	return (src);
}

char		**ft_array_realloc(char **src, char *key, char *value)
{
	int		i;
	int		size;
	char	**dest;

	size = 0;
	i = 0;
	if (key_exist(src, key) == 0)
	{
		while (src[size])
			size++;
		dest = (char**)malloc(sizeof(char*) * (size + 2));
		while (i < size)
		{
			dest[i] = (char*)malloc(sizeof(char) * ft_strlen(src[i]) + 1);
			ft_strcpy(dest[i], src[i]);
			i++;
		}
		//value ? (dest[i] = ft_strjoin(ft_strjoin(key, "="), value)) :
		//	(dest[i] = ft_strjoin(key, "="));
		if (value)
			dest[i] = ft_strjoin(ft_strjoin(key, "="), value);
		else
			dest[i] = ft_strjoin(key, "=");
		dest[++i] = NULL;
		free(src);
		return (dest);
	}
	return (value ? edit_key(src, key, value) : edit_key(src, key, " "));
}
