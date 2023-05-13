/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:53:24 by mzarichn          #+#    #+#             */
/*   Updated: 2023/05/13 18:55:53 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_env_path(char **envp)
{
	char	*path;
	int		i;

	i = 0;
	path = NULL;
	while (envp[i] != NULL && envp[i][0] != '\0')
	{
		path = ft_strnstr(envp[i], "PATH=", 5);
		if (path)
		{
			path = ft_substr(path, 5, ft_strlen(path));
			break ;
		}
		i++;
	}
	return (path);
}

char	*path_finder(char *cmd)
{
	char	**paths;
	char	*cmd_path;
	int		i;
	char	*env;

	env = get_env_path(data()->envp);
	paths = ft_split(env, ':');
	free(env);
	cmd = ft_strjoin("/", cmd);
	i = 0;
	while (paths[i])
	{
		cmd_path = ft_strjoin(paths[i], cmd);
		if (!access(cmd_path, F_OK))
		{
			_free(cmd, paths);
			return (cmd_path);
		}
		free(cmd_path);
		i++;
	}
	_free(NULL, paths);
	return (cmd);
}

void	get_infile(void)
{
	data()->infile = open(data()->av[1], O_RDONLY, 0644);
	if (data()->infile < 0)
		_error();
}

void	get_outfile(void)
{
	data()->outfile = open(data()->av[data()->ac - 1],
			O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (data()->outfile < 0)
		_error();
}