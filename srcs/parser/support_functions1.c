/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_functions1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:13:14 by lgertrud          #+#    #+#             */
/*   Updated: 2025/11/20 16:31:38 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_free_arraystruc(void **arr, int count)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (i++ < count)
		free(arr[i]);
	free(arr);
}
