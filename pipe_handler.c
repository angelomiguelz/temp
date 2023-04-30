/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:27:48 by mzarichn          #+#    #+#             */
/*   Updated: 2023/04/30 21:56:46 by mzarichn         ###   ########.fr       */
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
	int cmd;

	cmd = data()->pipe_quantity;

	i = 0;
	//printf("Cmds: %i\n", cmd);
	while (i < (cmd))
	{
		//printf("Closing Pipe n:%i\n", i);
		close(data()->pipes[i]);
		i++;
	}
}

void	allocate_pipes()
{
	//printf("Allocating Pipes\n");
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
	{
		if (pipe(&data()->pipes[i * 2 + 2]) < 0)
			_error("Error Creating Pipes");
	//	printf("creating pipes, %i\n", i);
	}
}