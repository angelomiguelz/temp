/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:37:15 by mzarichn          #+#    #+#             */
/*   Updated: 2022/11/10 12:50:37 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lastl;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	lastl = ft_lstlast(*lst);
	lastl->next = new;
}
