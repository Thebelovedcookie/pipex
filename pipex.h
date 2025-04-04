/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahfoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:58:32 by mmahfoud          #+#    #+#             */
/*   Updated: 2024/02/01 10:58:34 by mmahfoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
# include "./libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>

void	get_free(char **tab);
void	ft_exec(char **command, char **envp, char *str);
int		close_all(int *pipefd);

//main
char	**get_path_envp(char **envp);
char	*find_pathname(char **command, char **tab_path);
void	son(int *pipefd, char **argv, char **envp, int argc);
void	son2(int *pipefd, char **argv, char **envp);
int		ft_forking(char **argv, char **envp, int argc);

//error
void	exit_no_command(char **command, char *path_name, char *name_cmd);
void	exit_execve(char **command, char *path_name);
void	ex_pip(char *str);
void	ex_pid(char *str, int *pipefd);
void	exit_error(char *str);
#endif
