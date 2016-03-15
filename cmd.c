/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 10:49:43 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/03/15 12:19:08 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd(t_env *e, char **env)
{
	int		i;

	i = 1;
	ft_printf("Il y a %d path differnt\n", e->nbrpath);
	ft_printf("Il y a %d arguments differnt\n", e->nbarg);
	ft_printf("La commande taper est %s\n", e->cmd);
		ft_printf("Les argumennts sont %s\n", e->args[i]);
}
