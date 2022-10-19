#--PROJECT_NAME--#
PROJECT_NAME	= minishell

#--C FILES--# > all .c files
C_FILES			=	cd_utils.c dollar_utils2.c ft_strtrimfree.c pipex_utils.c search_cmds_cmd_utils.c quit_handle.c \
					check_n.c echo_utils.c get_home.c minishell.c print_intro.c search_cmds_fd_utils.c unset_utils.c checkenvformat.c		\
					envp_cp.c handle_builtin.c minishell_utils.c pwd_utils.c search_cmds_utils.c checkvalidarg.c export_utils.c				\
					handle_env.c parsing.c quotation.c set_exec_struct.c clear_whitespace.c export_utils2.c handle_exit.c parsing_utils.c	\
					rl_gets.c sig_utils.c dollar_utils.c free_memory.c heredoc.c pipex.c search_cmds.c singleton_statuscode.c	\
					misc_utils.c sig_utils2.c update_shlvl.c dollar_utils3.c cd_utils2.c export_utils3.c dollar_utils4.c


#--C FILES TO O FILES--# > where you make the .o files dependencies
O_FILES			= $(C_FILES:.c=.o)

#--NAME--# > name of the project
NAME			= $(PROJECT_NAME)

#--COMMANDS--# > all the bash command you will use in the Makefile
GCC					= gcc
MKDIR				= mkdir
RM					= rm
NORMINETTE			= norminette

#--FLAGS--# > flags used by the command above
ERROR_FLAGS 	= -Werror -Wall -Wextra
P_FLAG				= -p
O_FLAG				= -o
C_FLAG				= -c
RF_FLAG				= -rf
F_FLAG				= -f
DEBUG_FLAG			= -g
MAKE_C_FLAG 		= -C
LIBRARY_FLAG		= -L./lib -lft
RL_FLAG_MAC			= -L./lib -lreadline
RL_FLAG_LINUX		= -lreadline
LCURSES				= -lcurses

#--DIR PATH--# > path to the file
SRC_DIR				= src/
OBJ_DIR				= obj/
INC_DIR				= include/
LIBFT_DIR			= libft/

#--PREFIX--#
PRE_SRC				= $(addprefix $(SRC_DIR), $(C_FILES))
PRE_OBJ				= $(addprefix $(OBJ_DIR), $(O_FILES))

#--VPATH--#
VPATH				= $(SRC_DIR)

#--VAR--#
MY_VAR := $(shell uname)

#--ACTIONS--# > all the thing you want your Makefile to do
$(OBJ_DIR)%.o:		%.c
				@$(MKDIR) $(P_FLAG) $(OBJ_DIR)
				@$(GCC) $(ERROR_FLAGS) $(DEBUG_FLAG) $(O_FLAG) $@ $(C_FLAG) $<

$(NAME):			$(PRE_OBJ)
				@echo "Compiling $(PROJECT_NAME)..."
				@$(MAKE) $(MAKE_C_FLAG) $(LIBFT_DIR)
ifeq ($(MY_VAR), Linux)
	@$(GCC) $(ERROR_FLAGS) $(DEBUG_FLAG) $(PRE_OBJ) $(O_FLAG) $(NAME) $(LIBRARY_FLAG) $(RL_FLAG_LINUX) $(LCURSES)
else
	@$(GCC) $(ERROR_FLAGS) $(DEBUG_FLAG) $(PRE_OBJ) $(O_FLAG) $(NAME) $(LIBRARY_FLAG) $(RL_FLAG_MAC) $(LCURSES)
endif
				@echo "Compiling $(PROJECT_NAME) done."

all:				$(NAME)

clean:
				@echo "Removing $(PROJECT_NAME) object files..."
				@$(MAKE) $(MAKE_C_FLAG) $(LIBFT_DIR) clean
				@$(RM) $(F_FLAG) $(PRE_OBJ)
				@$(RM) $(RF_FLAG) $(OBJ_DIR)
				@echo "Removing $(PROJECT_NAME) object files done."

fclean:				clean
				@echo "Removing $(PROJECT_NAME) program..."
				@$(MAKE) $(MAKE_C_FLAG) $(LIBFT_DIR) fclean
				@$(RM) $(F_FLAG) $(NAME)
				@echo "Removing $(PROJECT_NAME) program done."

re:					fclean all

norminette:
				@$(NORMINETTE) $(SRC_DIR) $(INCLUDE_DIR)

.PHONY: all fclean clean re norminette 
