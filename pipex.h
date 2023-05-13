/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 15:16:43 by mzarichn          #+#    #+#             */
/*   Updated: 2023/05/13 18:23:47 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "./libft/libft.h"

typedef struct s_data {
	int	ac;
	char **av;
	char **envp;
	int	infile;
	int	outfile;
	int nchild;
	char **cmd_commands;
	char *cmd_path;
} t_data;

t_data *data(void);
void	_error(void);
void	get_infile(void);
void	get_outfile(void);
char	*path_finder(char *cmd);
void	_process();
void	_free(char *string, char **matrix);
void	_usage(void);
void	_executer(void);
void	_error(void);
void	_cmd_check(void);

#endif