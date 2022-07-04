#include "../include/minishell.h"

int main()
{
	t_cmd *cmd1 = malloc(sizeof(t_cmd));
	t_cmd *cmd2 = malloc(sizeof(t_cmd));
	t_cmd *cmd3 = malloc(sizeof(t_cmd));

	cmd1->argv = calloc(sizeof(char *), 3);
	cmd2->argv = calloc(sizeof(char *), 3);
	cmd3->argv = calloc(sizeof(char *), 3);

	cmd1->cmd = "/usr/bin/cat";
	cmd1->argv[0] = "cat";
	cmd1->argv[1] = "main_test.c";
	cmd1->first = 1;

	cmd2->cmd = "/usr/bin/grep";
	cmd2->argv[0] = "grep";
	cmd2->argv[1] = "malloc";
	cmd2->first = 0;

	cmd3->cmd = "/usr/bin/wc";
	cmd3->argv[0] = "wc";
	cmd3->argv[1] = "-l";
	cmd3->first = 0;

	cmd1->next = cmd2;
	cmd2->next = cmd3;
	cmd3->next = NULL;

	pipex(cmd1);
}
