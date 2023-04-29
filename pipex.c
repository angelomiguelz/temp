/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 15:08:00 by mzarichn          #+#    #+#             */
/*   Updated: 2023/04/29 20:21:54 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* void	pexit(char *s)
{
	perror(s);
	exit(1);
}

void	parent_process(int *piepinho, char **av, char **envp)
{
	int outfile;

	outfile = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (outfile == -1)
		pexit("erro no outfile parent process");
	dup2(outfile, STDOUT_FILENO);
	dup2(piepinho[0], STDIN_FILENO);
	close(piepinho[1]);
	if (execve(path_finder(av[3], envp), ft_split(av[3], ' '), envp) == -1)
		exit(1);
}

void	child_process(int *piepinho, char **av, char **envp)
{
	int infile;

	infile = open(av[1], O_CREAT | O_RDONLY, 0644);
	if (infile == -1)
		perror("erro no infile child process");
	dup2(piepinho[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(piepinho[0]);
	if (execve(path_finder(av[2], envp), ft_split(av[2], ' '), envp) == -1)
		exit(1);
} */

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

int main(int ac, char **av, char **envp)
{
	data()->envp = envp;
	data()->ac = ac;
	data()->av = av;
	get_infile();
	get_outfile();
	allocate_pipes();
	create_pipes();
	create_forks();
	close_pipes();
	waitpid(-1, NULL, 0);
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