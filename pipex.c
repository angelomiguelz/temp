/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 15:08:00 by mzarichn          #+#    #+#             */
/*   Updated: 2023/05/13 16:11:04 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_data *data(void)
{
	static t_data data;
	return (&data);
}

void	_error(char *s)
{
	perror(s);
	exit (1);
}

void	_initialization(int ac, char **av, char **envp)
{
	data()->envp = envp;
	data()->ac = ac;
	data()->av = av;
	data()->ncmds = ac - 3;
	data()->pipes = malloc(sizeof(int) * 2 * (data()->ncmds - 1));
	if (!data()->pipes)
		_error("Error in Pipe Memory Allocation");
	data()->pid = malloc(sizeof(int) * data()->ncmds);
	if (!data()->pid)
		_error("error in pid memory allocation");
	get_infile();
	get_outfile();
}

int main(int ac, char **av, char **envp)
{
	int	i;

	i = 2;
	if (ac >= 5)
	{
		_initialization(ac, av, envp);
			
	}
	create_pipes();
	_process();
}

/* int main(int ac, char **av, char **envp)
{
		if (pipe(piepinho) == -1)
			perror("Erro no piepinho");
		pid = fork();
		if (pid == -1)
			perror("erro no fork");
		if (pid == 0)
			child_process(piepinho, av, envp);
		parent_process(piepinho, av, envp);
} */