/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 15:16:43 by mzarichn          #+#    #+#             */
/*   Updated: 2023/05/27 14:07:48 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/src/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>

typedef struct s_data
{
	int		ac;
	char	**av;
	char	**envp;
	int		infile;
	int		outfile;
	int		nchild;
}			t_data;

t_data		*data(void);
void		_error(char *s);
void		get_infile(void);
void		get_outfile(void);
char		*path_finder(char *cmd, char **envp);
void		_process(void);
void		_free(char *string, char **matrix);
void		_usage(void);
void		_executer(void);
void		_cmd_check(void);
char		*find_path(char *cmd, char **envp);

#endif