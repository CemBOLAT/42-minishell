/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myagiz <myagiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:35:59 by myagiz            #+#    #+#             */
/*   Updated: 2023/07/19 12:24:23 by myagiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_quote_len(char *token, int *end, char quote)
{
	int	index;

	index = 0;
	*end = -1;
	while (1)
	{
		(*end)++;
		if (token[index] == quote || !token[index])
			return ;
		index++;
	}
}

void	ft_free_str_join(char **str, char *append)
{
	char	*old;

	if (!append)
		return ;
	old = *str;
	*str = ft_strjoin(*str, append, ft_strlen(*str) + ft_strlen(append) + 1);
	free(old);
}

void	get_len_of_word(char *s, int *end)
{
	int	index;

	index = -1;
	*end = 0;
	while (s[++index] && !(s[index] == '"' || s[index] == '\''))
		(*end)++;
}
