/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:08:17 by mzarichn          #+#    #+#             */
/*   Updated: 2023/04/30 21:56:19 by mzarichn         ###   ########.fr       */
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

char	*path_finder(char *cmd, char **envp)
{
	char *sub;
	char **paths;
	char *cmd_path;

	cmd = *ft_split(cmd, ' ');
	while (*data()->envp && !ft_strnstr(*data()->envp, "PATH=", 5))
		envp++;
	sub = ft_substr(*data()->envp, 5, ft_strlen(*data()->envp) - 5);
	paths = ft_split(sub, ':');
	free(sub);
	sub = ft_strjoin("/", cmd);
	while (*paths)
	{
		cmd_path = ft_strjoin(*paths, sub);
		if (!cmd_path)
			return (NULL);
		if (!access(cmd_path, F_OK))
			break ;
		free(cmd_path);
		paths++;
	}
	free(sub);
	free(cmd);
	return (cmd_path);	
}