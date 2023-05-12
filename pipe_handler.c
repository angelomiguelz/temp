/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:27:48 by mzarichn          #+#    #+#             */
/*   Updated: 2023/05/10 11:19:42 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_pipes()
{
	close(data()->infile);
	close(data()->outfile);
	free(data()->pipes);
	write(2, "Error allocating pipes", 23);
	exit (1);
}

void	create_pipes()
{
	int	i;

	i = -1;
	while (++i < data()->ncmds - 1)
		if (pipe(data()->pipes + 2 * i) == -1)
			_error("Error Creating Pipes");
}