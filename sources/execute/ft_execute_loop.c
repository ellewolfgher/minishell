/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_loop.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 19:00:23 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/11 16:58:04 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// static void	free_all_paths(char **all_paths)
// {
// 	int	i;

// 	i = 0;
// 	while (all_paths[i])
// 		free(all_paths[i++]);
// 	free(all_paths);
// }

// static char	*access_all_paths(char **all_paths)
// {
// 	int		i;

// 	i = 0;
// 	while (all_paths[i])
// 	{
// 		if (!access(all_paths[i], F_OK))
// 		{
// 			if (!access(all_paths[i], X_OK))
// 				return (ft_strdup(all_paths[i]));
// 		}
// 		i++;
// 	}
// 	return (NULL);
// }

// static int	get_path_index_from_envp(char **envp)
// {
// 	int	i;

// 	i = 0;
// 	while (envp[i])
// 	{
// 		if (envp[i][0] == 'P')
// 			if (envp[i][1] == 'A')
// 				if (envp[i][2] == 'T')
// 					if (envp[i][3] == 'H')
// 						if (envp[i][4] == '=')
// 							break ;
// 		i++;
// 	}
// 	if (envp[i])
// 		return (i);
// 	else
// 		return (-1);
// }

// static char	**cat_cmd_to_all_paths(char *cmd_arg, char **all_paths)
// {
// 	int		i[3];
// 	char	*temp;

// 	i[0] = 0;
// 	i[1] = 0;
// 	i[2] = 0;
// 	while (all_paths[i[0]])
// 	{
// 		temp = malloc (sizeof (char) * (ft_strlen(cmd_arg)
// 					+ 2 + ft_strlen(all_paths[i[0]])));
// 		while (all_paths[i[0]][i[1]])
// 		{
// 			temp[i[1]] = all_paths[i[0]][i[1]];
// 			i[1]++;
// 		}
// 		temp[i[1]++] = '/';
// 		while (cmd_arg[i[2]])
// 			temp[i[1]++] = cmd_arg[i[2]++];
// 		temp[i[1]] = '\0';
// 		i[1] = 0;
// 		i[2] = 0;
// 		free(all_paths[i[0]]);
// 		all_paths[i[0]++] = temp;
// 	}
// 	return (all_paths);
// }

// char	*get_path(char *cmd_arg, char **envp)
// {
// 	char	**all_paths;
// 	int		i;
// 	char	*path;

// 	if (!ft_strncmp(cmd_arg, ".", 1))
// 		return (ft_strdup(cmd_arg));
// 	i = get_path_index_from_envp (envp);
// 	if (1 < 0)
// 		write(2, "Error getting path index from ENVP\n", 35);
// 	all_paths = ft_split(envp[i] + 5, ':');
// 	all_paths = cat_cmd_to_all_paths(cmd_arg, all_paths);
// 	path = access_all_paths(all_paths);
// 	if (path)
// 	{
// 		free_all_paths(all_paths);
// 		return (path);
// 	}
// 	free_all_paths(all_paths);
// 	free(path);
// 	return (NULL);
// }

// static pid_t	create_child(void)
// {
// 	pid_t	child_pid;

// 	child_pid = fork();
// 	if (child_pid < 0)
// 	{
// 		write(2, "error: Can't spawn child\n", 25);
// 		exit(-1);
// 	}
// 	return (child_pid);
// }

// int	get_exec_error(char *path, t_ms_data *ms)
// {
// 	struct stat	sb;

// 	if (stat(path, &sb) == 0 && S_ISDIR(sb.st_mode))
// 	{
// 		ms->exit_code = 126;
// 		printf("Is a directory!\n");
// 	}
// 	if (!path)
// 		ms->exit_code = 1;
// 	else if (access(path, X_OK))
// 	{
// 		ms->exit_code = 127;
// 		ft_putstr_fd(path, STDERR_FILENO);
// 		ft_putstr_fd(": command not found!\n", STDERR_FILENO);
// 	}
// 	return (ms->exit_code);
// }

// int	pipe_handle(t_ms_data *ms, t_com *cmd)
// {
// 	if (cmd->receives_from_pipe)
// 	{
// 		close(ms->pipe_in[1]);
// 		dup2(ms->pipe_in[0], STDIN_FILENO);
// 	}
// 	if (cmd->sends_to_pipe)
// 	{
// 		close(ms->pipe_out[0]);
// 		dup2(ms->pipe_out[1], STDOUT_FILENO);
// 	}
// 	return (0);
// }

// int	exec_fork_builtin(t_com *cmd, t_ms_data *ms, int original_fds[2])
// {
// 	int	pid;

// 	pid = create_child();
// 	if (!pid)
// 	{
// 		sig_defaults();
// 		pipe_handle(ms, cmd);
// 		if (handle_redirects(cmd, original_fds, ms))
// 		{
// 			ms->issue_exit = -1;
// 			return (restore_original_fds(original_fds));
// 		}
// 		ms->issue_exit = -1;
// 		return (exec_builtin(cmd, ms, original_fds));
// 	}
// 	return (ms->exit_code);
// }

// /*
// ** Executes a command.
// */
// int	exec_com(t_com *cmd, t_ms_data *ms, int original_fds[2])
// {
// 	int		pid;

// 	pid = create_child();
// 	if (!pid)
// 	{
// 		ms->exit_code = 0;
// 		if (!get_exec_error(cmd->command, ms))
// 		{
// 			sig_defaults();
// 			if (handle_redirects(cmd, original_fds, ms))
// 			{
// 				ms->issue_exit = -1;
// 				return (restore_original_fds(original_fds));
// 			}
// 			execve(cmd->command, cmd->args, cmd->envp);
// 		}
// 		else
// 			ms->issue_exit = -1;
// 		return (ms->exit_code);
// 	}
// 	return (ms->exit_code);
// }

// int	exec_com_multi(t_com *cmd, t_ms_data *ms, int original_fds[2])
// {
// 	int		pid;

// 	pid = create_child();
// 	if (!pid)
// 	{
// 		ms->exit_code = 0;
// 		if (!get_exec_error(cmd->command, ms))
// 		{
// 			sig_defaults();
// 			pipe_handle(ms, cmd);
// 			if (handle_redirects(cmd, original_fds, ms))
// 			{
// 				ms->issue_exit = -1;
// 				return (restore_original_fds(original_fds));
// 			}
// 			execve(cmd->command, cmd->args, cmd->envp);
// 		}
// 		else
// 			ms->issue_exit = -1;
// 		return (ms->exit_code);
// 	}
// 	close(ms->pipe_in[0]);
// 	close(ms->pipe_in[1]);
// 	return (ms->exit_code);
// }

// // Returns 1 if a pipe operator is found.
// int	has_pipe(t_tokens *tokens)
// {
// 	t_tokens	*head;

// 	head = tokens;
// 	while (head)
// 	{
// 		if (head->type == OPTOKEN && !ft_strcmp(head->value, "|"))
// 			return (1);
// 		head = head->next;
// 	}
// 	return (0);
// }

// // Returns the function of the first builtin found.
// int	exec_builtin(t_com *cmd, t_ms_data *ms, int original_fds[2])
// {
// 	if (!cmd->sends_to_pipe && !cmd->receives_from_pipe)
// 	{
// 		if (handle_redirects(cmd, original_fds, ms))
// 			return (restore_original_fds(original_fds));
// 	}
// 	if (!ft_strcmp(cmd->command, "echo"))
// 		return (builtin_echo(cmd->args));
// 	if (!ft_strcmp(cmd->command, "cd"))
// 		return (builtin_cd(cmd->args, cmd->envp, ms));
// 	if (!ft_strcmp(cmd->command, "pwd"))
// 		return (builtin_pwd(cmd->args, cmd->envp, ms));
// 	if (!ft_strcmp(cmd->command, "export"))
// 		return (builtin_export(cmd->args, ms));
// 	if (!ft_strcmp(cmd->command, "unset"))
// 		return (builtin_unset(cmd->args, ms));
// 	if (!ft_strcmp(cmd->command, "env"))
// 		return (builtin_env(cmd->args, cmd->envp, ms->env_head));
// 	if (!ft_strcmp(cmd->command, "exit"))
// 		return (builtin_exit(cmd, cmd->args, cmd->envp, ms));
// 	return (0);
// }

// // Handles single-command input - either builtin or not.
// int	ft_execute_only_one(t_execute *cmd, t_data *ms, int original_fds[2])
// {
// 	if (ms->issue_exit)
// 		return (ms->issue_exit);
// 	if (cmd->is_builtin)
// 		ms->exit_code = exec_builtin(cmd, ms, original_fds);
// 	else
// 		ms->exit_code = exec_com(cmd, ms, original_fds);
// 	return (0);
// }

int	ft_execute_loop(t_execute *command, t_data *ms, int ogfds[2])
{
	(void)ogfds;
	if (!command)
		return (0);
	if (command->block_exec)
	{
		write (2, command->error_to_print, ft_strlen(command->error_to_print));
		return (0);
	}
	ft_execute_redir_create(command);
	if (!command->receives_from_pipe && !command->sends_to_pipe)
	{
		// ft_execute_only_one(command, ms, ogfds);
		return (0);
	}
	else if (!ms->need_to_exit)
		return (0);
		// return (exec_multi(command, ms, ogfds));
	return (1);
}
