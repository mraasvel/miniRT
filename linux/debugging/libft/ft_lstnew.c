/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 14:42:09 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/10/28 18:32:04 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*entry;

	entry = (t_list*)malloc(1 * sizeof(t_list));
	if (entry == 0)
		return (0);
	entry->content = content;
	entry->next = 0;
	return (entry);
}
