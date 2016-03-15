/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <nahmed-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 19:03:42 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/03/15 11:05:44 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft/includes/libft.h"
# include <stdlib.h>
# include <unistd.h>

# define DEBUG ft_printf("DEBUG : LINE : %d : FUNC %s\n", __LINE__, __func__);
typedef struct s_env
{
	char	*path;
	int		nbrpath;
	char	*cmd;
	char	**args;
	int		nbarg;
	char error;
}				t_env;

/*
** Parser
*/
char	*get_env(char **env);
void	parse_user(char *buffer, t_env *e);
/*
** Utils
*/
void	error(char *str, t_env *e);
/*
**	CLI
*/
void	cmd(t_env *e, char **env);
#endif
