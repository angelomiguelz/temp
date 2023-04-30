/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:53:24 by mzarichn          #+#    #+#             */
/*   Updated: 2023/04/30 21:56:56 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	my_dup(int input, int output)
{
	dup2(input, STDIN_FILENO);
	dup2(output, STDOUT_FILENO);
}

void	process_forks()
{
	data()->pid = fork();
	
	if (!data()->pid)
	{
		if (data()->pipe_order == 0)
			my_dup(data()->infile, data()->pipes[1]);
		else if (data()->pipe_order == data()->cmds - 1)
			my_dup(data()->pipes[2 * data()->pipe_order - 2], data()->outfile);
		else
			my_dup(data()->pipes[2 * data()->pipe_order - 2], data()->pipes[2 * data()->pipe_order + 1]);
		close_pipes();
		//printf("Closing Fork Pipes\n");
		if (execve(path_finder(data()->av[2 + data()->pipe_order], data()->envp), ft_split(data()->av[2 + data()->pipe_order], ' '), data()->envp) == -1)
			exit(1);
	}
/* 	else
		_error("Error in Forking"); */
}

void	create_forks()
{
	//printf("Creating Forks\n");
	data()->pipe_order = -1;
	while (++(data()->pipe_order) < data()->ac - 3)
	{
		//printf("Fork n: %i\n", data()->pipe_order);
		process_forks();
	}
}