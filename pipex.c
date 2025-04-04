/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahfoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:59:08 by mmahfoud          #+#    #+#             */
/*   Updated: 2024/02/01 10:59:10 by mmahfoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_path_envp(char **envp)
{
	int		i;
	char	**path_name;
	char	**final_tab;

	i = 0;
	path_name = NULL;
	final_tab = NULL;
	if (*envp != NULL)
	{
		while (envp[++i])
		{
			if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			{
				path_name = ft_split(envp[i], '=');
				break ;
			}
		}
		if (path_name != NULL)
		{
			final_tab = ft_split(path_name[1], ':');
			get_free(path_name);
			return (final_tab);
		}
	}
	return (NULL);
}

char	*find_pathname(char **command, char	**tab_path)
{
	int		i;
	char	*command_str;
	char	*full_join;

	i = 0;
	if (access(command[0], X_OK) == 0)
		return (get_free(tab_path), ft_strdup(command[0]));
	if (tab_path == NULL)
		return (NULL);
	command_str = ft_strjoin("/", command[0]);
	while (tab_path[i])
	{
		full_join = ft_strjoin(tab_path[i], command_str);
		if (access(full_join, X_OK) == 0)
		{
			get_free(tab_path);
			free(command_str);
			return (full_join);
		}
		free(full_join);
		i++;
	}
	free(command_str);
	get_free(tab_path);
	return (NULL);
}

void	son(int *pipefd, char **argv, char **envp, int argc)
{
	char	**command;
	int		fd_out;

	close(pipefd[1]);
	dup2(pipefd[0], 0);
	close(pipefd[0]);
	fd_out = open(argv[4], O_CREAT | O_TRUNC | O_WRONLY, 0666);
	if (fd_out < 0)
	{
		perror(argv[argc - 1]);
		exit(EXIT_FAILURE);
	}
	dup2(fd_out, 1);
	close(fd_out);
	if (ft_strncmp(argv[3], " ", 1) == 0)
	{
		ft_fprintf(2, "%s : Command not found\n", argv[3]);
		exit(EXIT_FAILURE);
	}
	command = NULL;
	command = ft_split(argv[3], ' ');
	ft_exec(command, envp, argv[3]);
	dprintf(2, "not finished son 1\n");
}

void	son2(int *pipefd, char **argv, char **envp)
{
	char	**command;
	int		fd_in;

	close(pipefd[0]);
	dup2(pipefd[1], 1);
	close(pipefd[1]);
	fd_in = open(argv[1], O_RDONLY);
	if (fd_in < 0)
	{
		perror(argv[1]);
		exit(EXIT_FAILURE);
	}
	dup2(fd_in, 0);
	close(fd_in);
	if (ft_strncmp(argv[2], " ", 1) == 0)
	{
		ft_fprintf(2, "%s : Command not found\n", argv[2]);
		exit(EXIT_FAILURE);
	}
	command = NULL;
	command = ft_split(argv[2], ' ');
	ft_exec(command, envp, argv[2]);
}

int	main(int argc, char **argv, char **envp)
{
	int	status;

	status = 0;
	if (argc != 5)
	{
		ft_fprintf(2, "ERROR : wrong arg number\n");
		exit(EXIT_FAILURE);
	}
	status = ft_forking(argv, envp, argc);
	return (status);
}
