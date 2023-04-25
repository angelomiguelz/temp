/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:04:11 by mzarichn          #+#    #+#             */
/*   Updated: 2022/11/10 15:26:42 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*slst;

	if (!lst)
		return ;
	while (*lst)
	{
		slst = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = slst;
	}
	*lst = 0;
}
