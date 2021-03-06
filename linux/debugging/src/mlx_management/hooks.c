/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/03 12:26:46 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/04/13 20:30:29 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <X11/keysym.h>
#include <X11/keysymdef.h>
#include "minirt.h"
#include "mlx.h"
#include "ft_error.h"
#include "prototypes.h"
#include "render.h"
#include "debug.h" // rm
#include <stdio.h> // rm

static int	mouse_hook(int keycode, int x, int y, t_data *data)
{
	(void)keycode;
	data->DEBUG = true;
	debug_ray(data, x, y);
	data->DEBUG = false;
	return (success);
}

static int	key_hook(int keycode, t_data *data)
{
	t_bool	next;

	next = false;
	if (keycode == XK_Tab)
	{
		printf("NEW CAM\n");
		next_camera(data);
		next = true;
	}
	else if (keycode == XK_Escape)
		exit_program(data);
	else if (translate_camera(keycode, data->active_cam) == true)
		next = true;
	else if (rotate_camera(keycode, data->active_cam) == true)
		next = true;
	if (next == true)
		if (next_frame(data) != success)
			exit_program(data);
	return (success);
}

static int	close_window(int keycode, t_data *data)
{
	(void)keycode;
	exit_program(data);
	return (success);
}

void	activate_hooks(t_data *data)
{
	mlx_mouse_hook(data->mlx->win_ptr, mouse_hook, data);
	mlx_key_hook(data->mlx->win_ptr, key_hook, data);
	mlx_hook(data->mlx->win_ptr, 33, 0L, close_window, data);
}
