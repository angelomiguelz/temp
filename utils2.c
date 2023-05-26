/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:04:07 by mzarichn          #+#    #+#             */
/*   Updated: 2023/05/26 14:06:05 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	_error(char *s)
{
	ft_putstr_fd(s, 2);
	exit(1);
}

void	_usage(void)
{
	ft_putstr_fd("Error: Bad Argument Format\n", 2);
	ft_putstr_fd("Ex: ./pipex infile cmd1 cmd2...cmdn outfile\n", 1);
	exit(1);
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
}

void	_cmd_check(void)
{
	int	i;

	i = 2;
	while (i < data()->ac - 1)
	{
		if (!ft_strlen(data()->av[i]))
		{
			ft_putstr_fd("Error: Empty Command\n", 2);
			exit(1);
		}
		i++;
	}
}
