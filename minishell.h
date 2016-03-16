/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <nahmed-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 19:03:42 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/03/16 00:55:39 by nahmed-m         ###   ########.fr       */
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

typedef struct s_bull
{
	char		*code;
	void		(*f)(t_env *e, char **env);
}				t_bull;

/*
** Parser
*/
char	*get_env(char **env);
void	parse_user(char *buffer, t_env *e);
/*
** Utils
*/
void	error(char *filename, char *str, t_env *e);
char	**ft_array_str_cpy(char **src, char **dest, int size);
char	*cjoin(char *tmp, char *tmp2);
/*
**	CLI
*/
void	cmd(t_env *e, char **env);

/*
**	Bull
*/
int		is_bull(char *cmd, t_env *e, char **env);
void	cd(t_env *e, char **env);
void	ft_setenv(t_env *e, char **env);
void	ft_unsetenv(t_env *e, char **env);
void	ft_env(t_env *e, char **env);
void	ft_exit(t_env *e, char **env);
#endif
