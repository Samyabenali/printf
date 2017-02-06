/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 18:48:40 by sait-ben          #+#    #+#             */
/*   Updated: 2016/11/21 19:14:24 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *n_list;

	if (!lst)
		return (NULL);
	n_list = f(lst);
	n_list->next = ft_lstmap(lst->next, f);
	return (n_list);
}
