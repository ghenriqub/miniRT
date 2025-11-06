/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:42:30 by lgertrud          #+#    #+#             */
/*   Updated: 2025/11/06 17:46:18 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "libft.h"

# define ERROR_PARAM "ERROR!\nUsage: ./minirt <file.rt>"

void	ft_exit(char *message, int code);
int		ft_is_rt(char *file);

#endif