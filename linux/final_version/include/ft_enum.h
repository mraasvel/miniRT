/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_enum.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 17:47:00 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/02 21:58:27 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ENUM_H
# define FT_ENUM_H

typedef enum	e_bool
{
	false,
	true
}				t_bool;

typedef enum	e_errors
{
	error,
	success,
	arg_error,
	malloc_error,
	parse_error
}				t_errors;

#endif