/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:53:24 by mzarichn          #+#    #+#             */
/*   Updated: 2023/05/09 16:24:13 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	my_dup(int input, int output)
{
	if (dup2(input, STDIN_FILENO) == -1)
		_error("In Dup2");
	if (dup2(output, STDOUT_FILENO) == -1)
		_error("In Dup2");
}

void	_free(char *string, char **matrix)
{
	int	i;

	i = -1;
	if (string != NULL)
	{
		free(string);
		string = NULL;
	}
	if (matrix != NULL)
	{
		while (matrix[++i])
			free(matrix[i]);
	}
	free(matrix);
	matrix = NULL;
}

void	_close()
{
	int i;

	if (data()->infile != -1)
		close(data()->infile);
	if (data()->outfile != -1)
		close(data()->outfile);
	i = -1;
	while (++i < (data()->ncmds - 1) * 2)
		close(data()->pipes[i]);
}

void	_child()
{
	if (data()->nchild == 0)
		my_dup(data()->infile, data()->pipes[1]);
	else if (data()->nchild == data()->ncmds - 1)
		my_dup(data()->pipes[2 * data()->nchild - 2], data()->outfile);
	else
		my_dup(data()->pipes[2 * data()->nchild - 2], data()->pipes[2 * data()->nchild + 1]);
	_close();
	if (execve(data()->cmd_path, data()->cmd_commands, data()->envp) == -1)
		_error("Error in Child Process");
}

void	_parent()
{
	pid_t	wpid;
	int		status;
	int		exit_code;

	_close();
	exit_code = 1;
	while (--data()->nchild >= 0)
	{
		wpid = waitpid(data()->pid[data()->nchild], &status, 0);
		if (wpid == data()->pid[data()->ncmds - 1])
			if ((data()->nchild == (data()->ncmds - 1)) && WIFEXITED(status))
				exit_code = WEXITSTATUS(status);
	}
	printf("Exit code: %i\n", exit_code);
	free(data()->pipes);
	free(data()->pid);
}

void	_process()
{
	data()->nchild = 0;
	while (data()->nchild < data()->ncmds)
	{
		printf("Child n: %i\n", data()->nchild);
		data()->cmd_commands = ft_split(data()->av[data()->nchild + 2], ' ');
		if (!data()->cmd_commands)
			_error("Error in Cmd Commands Splitting");
		data()->cmd_path = path_finder(data()->cmd_commands[0]);
		printf("CMD PATH: %s\n", data()->cmd_path);
		data()->pid[data()->nchild] = fork();
		if (data()->pid[data()->nchild] == -1)
			_error("error in pid");
		else if (data()->pid[data()->nchild] == 0)
		{
			printf("Enter child\n");
			_child();
		}
		_free(data()->cmd_path, data()->cmd_commands);
		data()->nchild++;
	}
	_parent();
}
