/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 15:08:00 by mzarichn          #+#    #+#             */
/*   Updated: 2023/05/25 16:06:22 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_data	*data(void)
{
	static t_data	data;

	return (&data);
}

void	_initialization(int ac, char **av, char **envp)
{
	data()->envp = envp;
	data()->ac = ac;
	data()->av = av;
	data()->nchild = -1;
	_cmd_check();
	get_infile();
	get_outfile();
}

void	_process(void)
{
	pid_t	pid;
	int		fds[2];

	if (pipe(fds) == -1)
		_error();
	pid = fork();
	if (pid == -1)
		_error();
	if (pid == 0)
	{
		close(fds[0]);
		dup2(fds[1], STDOUT_FILENO);
		if (!_executer())
		{
			close(fds[1]);
			close(data()->infile);
			close(data()->outfile);
			_error();
		}
	}
	else
	{
		close(fds[1]);
		dup2(fds[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

int	_executer(void)
{
	char	*path;
	char	**cmd;

	cmd = ft_split(data()->av[data()->nchild], ' ');
	path = path_finder(cmd[0], data()->envp);
	if (execve(path, cmd, data()->envp) == -1)
		return (0);
	return (1);
}

int	main(int ac, char **av, char **envp)
{
	if (ac == 5)
	{
		_initialization(ac, av, envp);
		dup2(data()->infile, STDIN_FILENO);
		while (++data()->nchild < data()->ac - 2)
			_process();
		dup2(data()->outfile, STDOUT_FILENO);
		_executer();
	}
	_usage();
}
