/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:27:48 by mzarichn          #+#    #+#             */
/*   Updated: 2023/04/29 20:24:07 by mzarichn         ###   ########.fr       */
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

void	close_pipes()
{
	int	i;

	i = -1;
	while (++i < data()->cmds - 1)
		close(data()->pipes[i]);
}

void	allocate_pipes()
{
	data()->cmds = data()->ac - 3;
	data()->pipe_quantity = (data()->cmds - 1) * 2;
	data()->pipes = malloc(sizeof(int) * data()->pipe_quantity);
	if (!data()->pipes)
		free_pipes();
}

void	create_pipes()
{
	int	i;

	i = -1;
	while (++i < (data()->cmds) - 1)
		if (pipe(&data()->pipes[i * 2 + 2]) < 0)
			_error("Error Creating Pipes");
}