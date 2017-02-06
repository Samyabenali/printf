/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 17:03:22 by sait-ben          #+#    #+#             */
/*   Updated: 2016/11/21 19:11:57 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*stock;

	if (alst && del)
	{
		while (*alst)
		{
			stock = (*alst)->next;
			del((*alst)->content, (*alst)->content_size);
			free(*alst);
			*alst = stock;
		}
		*alst = NULL;
	}
}
