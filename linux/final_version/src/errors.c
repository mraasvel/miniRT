/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   errors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 20:47:51 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/07 19:51:45 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_error.h"
#include "minirt.h"

/*
** Wrapper for setting the error number
*/

int		ft_error(t_data *data, t_errors error_type)
{
	data->errnum = error_type;
	return (error_type);
}

void	ft_perror(t_errors error_type)
{
	static const char	*error_table[] = {
		"Standard Error",
		"Success",
		"Argument Error",
		"Malloc Error",
		"Parse Error",
		"MLX Error",
		"BMP Error",
		"Multithreading Error"
	};

	printf("Error\nType: %s\n", error_table[error_type]);
	perror("Perror");
}
