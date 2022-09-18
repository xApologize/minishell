#include "../include/minishell.h"

void	set_fd_in(t_cmd *cmd)
{
	if (!cmd)
		return ;
	while (*_data.line == '\0' && ft_strchr(" <", *_data.indexmeta))
	{
		_data.line++;
		_data.indexmeta++;
	}
	if (*_data.line == '\0' && *_data.indexmeta == ' ')
		return ;
	if (access(_data.line, F_OK) == 0)
	{
		cmd->redir_in = open(_data.line, O_RDWR);
		dup2(cmd->redir_in, STDIN_FILENO);
		close(cmd->redir_in);
	}
	while (*_data.line != '\0')
		_data.line++;
}

void	set_fd_out(t_cmd *cmd, int append)
{
	if (!cmd || !_data.line)
		return ;
	_data.indexmeta++;
	if (append == 1)
		_data.indexmeta++;
	while (*_data.line == '\0' && (*_data.indexmeta == ' ' || *_data.indexmeta == '\0'))
	{
		_data.line++;
		_data.indexmeta++;
	}
	if (append == 0)
		cmd->redir_out = open(_data.line, O_RDWR | O_CREAT, 0777);
	else
		cmd->redir_out = open(_data.line, O_RDWR | O_APPEND | O_CREAT, 0777);
	while (*_data.line != '\0')
		_data.line++;
}

void	get_fd(t_cmd *cmd, char meta)
{
	if (meta == '<')
	{
		if (_data.line[1] == '\0' && _data.indexmeta[1] == '<')
			cmd->redir_in = heredoc();
		else
			set_fd_in(cmd);
	}
	else if (meta == '>')
	{
		if (_data.line[1] == '\0' && _data.indexmeta[1] == '>')
			set_fd_out(cmd, 1);
		else
			set_fd_out(cmd, 0);
	}
}
