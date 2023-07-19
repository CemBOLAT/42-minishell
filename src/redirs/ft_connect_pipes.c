/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_connect_pipes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myagiz <myagiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:36:23 by myagiz            #+#    #+#             */
/*   Updated: 2023/07/19 12:24:23 by myagiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_close_pipes(void)
{
	int	i;

	i = 0;
	while (i < g_data->pipe_count)
		close(g_data->opened_pipes[i++]);
	free(g_data->opened_pipes);
	g_data->pipe_count = 0;
	g_data->opened_pipes = NULL;
}

void	ft_link_pipes(t_command **cmds, int i, int *pipes)
{
	if (cmds[i + 1] && i - 1 >= 0)
	{
		ft_add_arr_int(&(g_data->opened_pipes), g_data->pipe_count++, pipes[0]);
		cmds[i]->in = pipes[0];
		pipe(pipes);
		cmds[i]->out = pipes[1];
		ft_add_arr_int(&(g_data->opened_pipes), g_data->pipe_count++, pipes[1]);
	}
	else if (i == 0 && cmds[i + 1])
	{
		pipe(pipes);
		ft_add_arr_int(&(g_data->opened_pipes), g_data->pipe_count++, pipes[1]);
		cmds[i]->out = pipes[1];
	}
	else if (!cmds[i + 1])
	{
		cmds[i]->in = pipes[0];
		ft_add_arr_int(&(g_data->opened_pipes), g_data->pipe_count++, pipes[0]);
	}
}

void	ft_connect_pipes(t_command **cmd)
{
	int	pipes[2];
	int	i;
	int	len;

	i = -1;
	len = ft_matrix_len((void **)cmd);
	if (len == 1)
		return ;
	while (++i < len)
		ft_link_pipes(cmd, i, pipes);
}
