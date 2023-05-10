/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:08:17 by mzarichn          #+#    #+#             */
/*   Updated: 2023/05/09 19:00:55 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_infile(void)
{
	//printf("Getting infile\n");
	data()->infile = open(data()->av[1], O_CREAT | O_RDONLY, 0644);
	if (data()->infile < 0)
		_error("Infile Error"); 
}

void	get_outfile(void)
{
	//printf("Getting outfile\n");
	data()->outfile = open(data()->av[data()->ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (data()->outfile < 0)
		_error("Outfile Error");
}

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
	char *sub;
	char **paths;
	char *cmd_path;
	int	i;

	cmd = *ft_split(cmd, ' ');
	sub = get_env_path(data()->envp);
	paths = ft_split(sub, ':');
	free(sub);
	sub = ft_strjoin("/", cmd);
	i = 0;
	while (paths[i])
	{
		cmd_path = ft_strjoin(paths[i], sub);
		if (!cmd_path)
			return (NULL);
		if (!access(cmd_path, F_OK))
		{
			free(sub);
			free(cmd);
			return (cmd_path) ;
		}
		free(cmd_path);
		i++;
	}
	return (cmd);
}