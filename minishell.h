/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <nahmed-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 19:03:42 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/03/14 00:06:39 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft/includes/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_env
{
	char *path;
	char error;
}				t_env;

/*
** Parser
*/
char	*get_env(char **env);

/*
** Utils
*/
void	error(char *str, t_env *e);
#endif
