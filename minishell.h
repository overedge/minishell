/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <nahmed-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 19:03:42 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/03/23 15:07:50 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft/includes/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_env
{
	char		*path;
	int			nbrpath;
	char		*cmd;
	char		**args;
	int			nbarg;
	char		error;
	char		**env;
	int			nbcmd;
	char		**cmds;
}				t_env;

/*
** Parser
*/
char			*get_env(char **env);
void			parse_user(char *buffer, t_env *e);
void			parse_all_cmds(char *buffer, t_env *e);
/*
** Utils
*/
void			error(char *filename, char *str, t_env *e);
char			**ft_array_realloc(char **src, char *key, char *value);
char			*cjoin(char *tmp, char *tmp2);
char			*get_home(char **env);
char			*get_env(char **env);
char			**ft_array_str_cpy(char **src, char **dest);
char			**ft_array_unset(char **src, char *key);
char			**ft_unset_elem(char **src, char *key, int size);
/*
**	CLI
*/
void			cmd(t_env *e);

/*
**	Bull
*/
int				is_bull(char *cmd, t_env *e);
void			cd(t_env *e);
void			ft_setenv(t_env *e);
void			ft_unsetenv(t_env *e);
void			ft_env(t_env *e);
void			ft_exit(t_env *e);
#endif
