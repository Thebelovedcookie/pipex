/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahfoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:57:59 by mmahfoud          #+#    #+#             */
/*   Updated: 2024/02/01 10:58:06 by mmahfoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_free(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_exec(char **command, char **envp, char *str)
{
	char	**path_envp;
	char	*path_name;

	path_envp = NULL;
	path_name = NULL;
	if (command == NULL || (command[0] == NULL))
	{
		get_free(command);
		exit(EXIT_FAILURE);
	}
	path_envp = get_path_envp(envp);
	path_name = find_pathname(command, path_envp);
	if (path_name == NULL)
		exit_no_command(command, path_name, str);
	if (execve(path_name, command, envp) == -1)
		exit_execve(command, path_name);
}

int	ft_forking(char **argv, char **envp, int argc)
{
	int		pipefd[2];
	pid_t	pid[2];

	if (pipe(pipefd) == -1)
		ex_pip("pipe");
	pid[0] = fork();
	if (pid[0] == -1)
		ex_pid("pid", pipefd);
	if (pid[0] == 0)
		son(pipefd, argv, envp, argc);
	pid[1] = fork();
	if (pid[1] == -1)
		ex_pid("pid", pipefd);
	if (pid[1] == 0)
		son2(pipefd, argv, envp);
	return (close_all(pipefd));
}

int	close_all(int *pipefd)
{
	int	status;

	close(pipefd[1]);
	close(pipefd[0]);
	waitpid(-1, &status, 0);
	waitpid(-1, &status, 0);
	return (status);
}
