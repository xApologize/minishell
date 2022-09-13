#include "../include/minishell.h"

void	set_fd_in(t_cmd *cmd, t_data *data)
{
	if (!cmd || !data)
		return ;
	while (*data->line == '\0' && ft_strchr(" <", *data->indexmeta))
	{
		data->line++;
		data->indexmeta++;
	}
	if (*data->line == '\0' && *data->indexmeta == ' ')
		return ;
	//printf("line in: %s\n", data->line);
	if (access(data->line, F_OK) == 0)
		cmd->redir_in = open(data->line, O_RDWR);
	//printf("cmd->redir_in: %i\n", cmd->redir_in);
	while (*data->line != '\0')
		data->line++;
}

void	set_fd_out(t_cmd *cmd, int append, t_data *data)
{
	if (!cmd || !data->line)
		return ;
	//printf("line out: %s\n", data->line);
	data->indexmeta++;
	if (append == 1)
		data->indexmeta++;
	while (*data->line == '\0' && (*data->indexmeta == ' ' || *data->indexmeta == '\0'))
	{
		data->line++;
		data->indexmeta++;
	}
	if (append == 0)
		cmd->redir_out = open(data->line, O_RDWR | O_CREAT, 0777);
	else
		cmd->redir_out = open(data->line, O_RDWR | O_APPEND | O_CREAT, 0777);
	//printf("cmd->redir_out: %i\n", cmd->redir_out);
	while (*data->line != '\0')
		data->line++;
}

void	get_fd(t_cmd *cmd, t_data *data, char meta)
{
	if (meta == '<')
	{
		if (data->line[1] == '\0' && data->indexmeta[1] == '<')
			cmd->redir_in = heredoc(data);
		else
			set_fd_in(cmd, data);
	}
	else if (meta == '>')
	{
		if (data->line[1] == '\0' && data->indexmeta[1] == '>')
			set_fd_out(cmd, 1, data);
		else
			set_fd_out(cmd, 0, data);
	}
}
