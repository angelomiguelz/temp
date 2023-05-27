/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:53:24 by mzarichn          #+#    #+#             */
/*   Updated: 2023/05/27 14:12:18 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*path_finder(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	int		i;
	char	*part_path;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (!access(path, F_OK))
		{
			_free(NULL, paths);
			return (path);
		}
		free(path);
		i++;
	}
	_free(NULL, paths);
	return (cmd);
}

void	get_infile(void)
{
	(data()->infile) = open(data()->av[1], O_RDONLY, 0644);
	if (data()->infile < 0)
		perror("INFILE ERROR");
}

void	get_outfile(void)
{
	(data()->outfile) = open(data()->av[data()->ac - 1], \
								O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (data()->outfile < 0)
		perror("OUTFILE ERROR");
}
