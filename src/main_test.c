#include "../include/minishell.h"

int main()
{
	t_cmd *cmd1 = malloc(sizeof(t_cmd));
	t_cmd *cmd2 = malloc(sizeof(t_cmd));
	t_cmd *cmd3 = malloc(sizeof(t_cmd));

	cmd1->cmd = "allo";
	cmd2->cmd = "hello";
	cmd3->cmd = "world";

	cmd1->next = cmd2;
	cmd2->next = cmd3;
	cmd3->next = NULL;

	pipex(cmd1);
}
