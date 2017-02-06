/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 15:38:04 by sait-ben          #+#    #+#             */
/*   Updated: 2016/11/21 19:27:22 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*nlist;

	nlist = malloc(sizeof(t_list));
	if (nlist == NULL)
		return (NULL);
	if (!content)
	{
		nlist->content = NULL;
		nlist->content_size = 0;
	}
	else
	{
		nlist->content = malloc(sizeof(content));
		if (nlist->content == NULL)
			return (NULL);
		ft_memcpy(nlist->content, content, content_size);
		nlist->content_size = content_size;
	}
	nlist->next = NULL;
	return (nlist);
}
