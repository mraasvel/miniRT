/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersect_square.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/04 09:36:21 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/04 10:53:58 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include "raytracing.h"
#include "libft.h"

static t_bool	point_in_square(t_vec3 point, t_square *square)
{
	t_vec3	local;
	float	half_size;

	half_size = square->size / 2.f;
	local = matrix_vec_mult(square->cob_matrix, point);
	if (ft_fabs(local.x) <= half_size && ft_fabs(local.y) <= half_size)
		return (true);
	return (false);
}

/*
** 1. Intersect plane square
** lies on
** 2. Convert point to local
** square coordinate system
** 3. Check up and right vectors
** if they fit inside the square
*/

t_bool			intersect_square(t_ray *ray, void *object)
{
	t_square	*square;
	float		t;
	t_vec3		intersection;

	square = (t_square*)object;
	t = intersect_plane_wrap(*ray, square->norm, square->pos);
	if (t <= 0)
		return (false);
	intersection = vec_add(ray->origin, vec_scalar(t, ray->dir));
	if (point_in_square(intersection, square) == false)
		return (false);
	return (update_ray(ray, t, object));
}
