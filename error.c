/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahfoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:56:31 by mmahfoud          #+#    #+#             */
/*   Updated: 2024/02/03 15:37:50 by mmahfoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_no_command(char **command, char *path_name, char *name_cmd)
{
	free(path_name);
	get_free(command);
	if (ft_strncmp(name_cmd, "/", 1) != 0)
	{
		ft_fprintf(2, "%s : Command not found\n", name_cmd);
		exit(EXIT_FAILURE);
	}
	else
		exit_error(name_cmd);
}

void	exit_execve(char **command, char *path_name)
{
	free(path_name);
	get_free(command);
	exit_error("Execve");
}

void	ex_pip(char *str)
{
	exit_error(str);
}

void	ex_pid(char *str, int *pipefd)
{
	close(pipefd[0]);
	close(pipefd[1]);
	exit_error(str);
}

void	exit_error(char	*str)
{
	perror(str);
	exit(EXIT_FAILURE);
}
