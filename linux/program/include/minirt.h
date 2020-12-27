/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minirt.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/26 09:57:25 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/27 23:08:50 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

typedef enum	e_errnums
{
	success,
	error,
	input_error,
	option_error,
	argc_error,
	gnl_error,
	file_error,
	open_error,
	read_error,
	write_error,
	malloc_error
}				t_errnums;

typedef struct	s_vec3
{
	double	x;
	double	y;
	double	z;
}				t_vec3;

#endif
