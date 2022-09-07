#include "../include/minishell.h"

int main()
{
	t_cmd *cmd1 = malloc(sizeof(t_cmd));
	t_cmd *cmd2 = malloc(sizeof(t_cmd));
	t_cmd *cmd3 = malloc(sizeof(t_cmd));
	t_cmd *cmd4 = malloc(sizeof(t_cmd));

	cmd1->argv = calloc(sizeof(char *), 3);
	cmd2->argv = calloc(sizeof(char *), 3);
	cmd3->argv = calloc(sizeof(char *), 3);
	cmd4->argv = calloc(sizeof(char *), 3);

	// cmd1->cmd = "/bin/sleep";
	// cmd1->argv[0] = "sleep";
	// cmd1->argv[1] = "5";
 //
	// cmd2->cmd = "/bin/sleep";
	// cmd2->argv[0] = "sleep";
	// cmd2->argv[1] = "2";
 //
	// cmd1->next = cmd2;
	// cmd2->next = NULL;

	cmd1->cmd = "/bin/cat2";
	cmd1->argv[0] = "cat2";
	cmd1->argv[1] = "main_test_pipex.c";

	cmd2->cmd = "/usr/bin/g3rep";
	cmd2->argv[0] = "g3rep";
	cmd2->argv[1] = "calloc";

	cmd3->cmd = "/usr/bin/hewad";
	cmd3->argv[0] = "hewad";
	cmd3->argv[1] = "-2";

	cmd4->cmd = "/usr/bin/wc";
	cmd4->argv[0] = "wc";

	cmd1->next = cmd2;
	cmd2->next = cmd3;
	cmd3->next = cmd4;
	cmd4->next = NULL;
	pipex(cmd1);
}
