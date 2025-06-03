COMP = cc
CFLAG = -Wall -Wextra -Werror -g3 -MMD
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include
NAME = PrimeSH

SRC = $(shell find $(SRC_DIR) -name "*.c")
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
DEP = $(OBJ:.o=.d)

LIBFT_DIR = lib/libft
PRINTF_DIR = lib/printf
GNL_DIR = lib/gnl
GC_DIR = lib/garbage_collector
GD_DIR = lib/garbage_descriptor

LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a
GNL = $(GNL_DIR)/libftgnl.a
GC = $(GC_DIR)/libgarbage_collector.a
GD = $(GD_DIR)/libgarbage_descriptor.a

LIBS = $(LIBFT) $(PRINTF) $(GNL) $(GC) $(GD)

LDFLAGS = -lreadline
all: clear_terminal libs $(NAME)
	@echo "\033[1;32m💥 Compilation terminée ! 💥\033[0m"
	@echo "\033[1;33m🔨 Projet prêt ! Lancer avec ./$(NAME)\033[0m"

libs:
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR)
	@$(MAKE) --no-print-directory -C $(PRINTF_DIR)
	@$(MAKE) --no-print-directory -C $(GNL_DIR)
	@$(MAKE) --no-print-directory -C $(GC_DIR)
	@$(MAKE) --no-print-directory -C $(GD_DIR)

clear_terminal:
	@clear

$(NAME): $(OBJ) $(LIBS)
	@echo "\033[1;33m🔧 Liaison...\033[0m"
	@$(COMP) $(CFLAG) $(OBJ) $(LIBS) -o $(NAME) $(LDFLAGS)
	@echo "\033[1;32m🚀 $(NAME) généré !\033[0m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "\033[1;34m📂 Compilation $<...\033[0m"
	@$(COMP) $(CFLAG) -I$(INC_DIR) -c $< -o $@
	@echo "\033[1;32m✅ $< compilé !\033[0m"

clean: clear_terminal
	@echo "\033[1;31m🧹 Suppression des .o et .d...\033[0m"
	@rm -rf $(OBJ_DIR)
	@echo "\033[1;32m🗑️ .o et .d supprimés.\033[0m"
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) clean
	@$(MAKE) --no-print-directory -C $(PRINTF_DIR) clean
	@$(MAKE) --no-print-directory -C $(GNL_DIR) clean
	@$(MAKE) --no-print-directory -C $(GC_DIR) clean
	@$(MAKE) --no-print-directory -C $(GD_DIR) clean

fclean: clean
	@echo "\033[1;31m🔥 Suppression $(NAME)...\033[0m"
	@rm -f $(NAME)
	@echo "\033[1;32m🔥 $(NAME) supprimé.\033[0m"
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) fclean
	@$(MAKE) --no-print-directory -C $(PRINTF_DIR) fclean
	@$(MAKE) --no-print-directory -C $(GNL_DIR) fclean
	@$(MAKE) --no-print-directory -C $(GC_DIR) fclean
	@$(MAKE) --no-print-directory -C $(GD_DIR) fclean

re: fclean all
	@echo "\033[1;32m🔄 Recompilation terminée !\033[0m"

valgrind: all
	@echo "\033[1;33m🔍 Lancement de Valgrind...\033[0m"
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --suppressions=readline.supp ./$(NAME)
	@echo "\033[1;32m✅ Valgrind terminé !\033[0m"

-include $(DEP)

.PHONY: all clean fclean re clear_terminal libs valgrind
