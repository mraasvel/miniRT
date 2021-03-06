/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   multithreading.h                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 18:03:39 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/14 21:59:24 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MULTITHREADING_H
# define MULTITHREADING_H

# include "minirt.h"

# ifndef NUMTHREAD
#  define NUMTHREAD 4
# endif

# include <pthread.h>
# include "multithreading.h"

typedef struct	s_thread
{
	int		threadnum;
	t_data	*data;
}				t_thread;

#endif
