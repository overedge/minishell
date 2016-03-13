/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <nahmed-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 19:03:33 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/03/13 21:45:15 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main()
{
	char *buffer = NULL;
	t_env e;

	ft_memset(&e, 0, sizeof(e));
	while (42)
	{
		e.error == 0 ? ft_printf("🚀  > ") : ft_printf("💥  > ");
		get_next_line(0, &buffer);
		//traitement
		free(buffer);
	}
	return (0);
}
