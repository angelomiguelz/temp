/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 15:16:43 by mzarichn          #+#    #+#             */
/*   Updated: 2023/05/09 16:00:27 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"

typedef struct s_data {
	int	ac;
	char **av;
	char **envp;
	int	infile;
	int	outfile;
	int	*pid;
	int	*pipes;
	int ncmds;
	int nchild;
	int nparent;
	char **cmd_commands;
	char *cmd_path;
	int	is_doc;
} t_data;

t_data *data(void);
void	_error(char *s);
void	get_infile(void);
void	get_outfile(void);
void	allocate_pipes();
void	create_pipes();
void	close_pipes();
void	create_forks();
char	*path_finder(char *cmd);
void	_process();

#endif