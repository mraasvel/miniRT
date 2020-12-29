/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minirt.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/26 09:57:25 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/29 14:39:48 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define WINDOW_NAME "MiniMaarten"

typedef enum	e_errnums
{
	success,
	error,
	input_error,
	option_error,
	argc_error,
	gnl_error,
	file_error,
	mlx_error,
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

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}				t_mlx;

typedef struct	s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		byte_pp;
	int		size_line;
	int		endian;
}				t_img;

typedef union	u_color
{
	int		val;
	struct		s_rgb
	{
		unsigned char	b;
		unsigned char	g;
		unsigned char	r;
		unsigned char	t;
	}		rgb;
}				t_color;

#endif