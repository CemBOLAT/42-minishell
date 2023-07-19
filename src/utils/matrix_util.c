/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myagiz <myagiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:37:12 by myagiz            #+#    #+#             */
/*   Updated: 2023/07/17 12:37:12 by myagiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	**ft_dup_matrix(char **arr)
{
	char	**ret;
	int		i;

	ret = ft_calloc(sizeof(char *), ft_matrix_len((void **)arr) + 1);
	i = 0;
	while (arr && *arr)
		ret[i++] = ft_strdup(*arr++);
	ret[i] = NULL;
	return (ret);
}

int	ft_matrix_len(void **arr)
{
	int	len;

	len = 0;
	while (arr && arr[len])
		len++;
	return (len);
}

void	ft_free_matrix(void **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
		free(arr[i++]);
	free(arr);
}
