#--PROJECT_NAME--#
PROJECT_NAME	= minishell

#--C FILES--# > all .c files
C_FILES			= $(notdir $(wildcard src/*.c))

#--C FILES TO O FILES--# > where you make the .o files dependencies
O_FILES			= $(C_FILES:.c=.o)

#--NAME--# > name of the project
NAME			= $(PROJECT_NAME)

#--COMMANDS--# > all the bash command you will use in the Makefile
GCC						= gcc
MKDIR					= mkdir
RM						= rm
MAKE					= make
NORMINETTE		= norminette

#--FLAGS--# > flags used by the command above
ERROR_FLAGS 	= -Werror -Wall -Wextra
P_FLAG				= -p
O_FLAG				= -o
C_FLAG				= -c
RF_FLAG				= -rf
F_FLAG				= -f
DEBUG_FLAG		= -g
MAKE_C_FLAG 	= -C
LIBRARY_FLAG	= -L./libft -lft
RL_FLAG				= -L./lib -lreadline
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
VPATH					= $(SRC_DIR)

#--ACTIONS--# > all the thing you want your Makefile to do
$(OBJ_DIR)%.o:		%.c
				@$(MKDIR) $(P_FLAG) $(OBJ_DIR)
				@$(GCC) $(ERROR_FLAGS) $(O_FLAG) $@ $(C_FLAG) $<

$(NAME):			$(PRE_OBJ)
				@echo "Compiling $(PROJECT_NAME)..."
				@$(MAKE) $(MAKE_C_FLAG) $(LIBFT_DIR)
				@$(GCC) $(ERROR_FLAGS) $(DEBUG_FLAG) $(PRE_OBJ) $(O_FLAG) $(NAME) $(LIBRARY_FLAG) $(RL_FLAG) $(LCURSES)
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
