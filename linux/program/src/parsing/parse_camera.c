/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_camera.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/28 16:47:52 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/28 20:54:54 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "prototypes.h"

/*
** Invalid if:
** - Invalid number of parameters
** - Invalid number of coordinates
** - Invalid FOV (in range (0, 180)
** - Orientation vector is not normalized to magnitude 1
** Alternative: normalize the orientation vector yourself
*/

int	parse_camera(char **element, t_vect *cameras)
{
	t_camera	camera;

	if (check_information(element, 4) != success)
		return (file_error);
	if (parse_coordinates(element[1], &camera.position) != success)
		return (file_error);
	if (parse_coordinates(element[2], &camera.orientation) != success)
		return (file_error);
	if (vec_magnitude(camera.orientation) == 0)
		return (file_error);
	if (vec_magnitude(camera.orientation) != 1)
		vec_normalize(camera.orientation);
	if (check_number(element[3]) != success)
		return (file_error);
	camera.fov = ft_atoi(element[3]);
	if (!(camera.fov >= 0 && camera.fov <= 180))
		return (file_error);
	if (vect_pushback(cameras, &camera) == -1)
		return (malloc_error);
	return (success);
}