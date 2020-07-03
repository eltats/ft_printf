CFILES = clean_print.c dop.c field_parse.c flag_parse.c flags.c it.c it_utils.c mainout.c parser.c precision.c print_main.c roflan.c utils.c ft_floats.c pars_utils.c ft_flt_itoa.c float_utils.c
OBJS = $(CFILES:.c=.o)
NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror -O2
LIBFT = libft
all: $(NAME)
$(NAME): $(OBJS)
	@make -sC $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
%.o:%.c
	@gcc $(FLAGS) -o $@ -c $<
include $(wildcard *.d)
clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)
	@make clean -C $(LIBFT)
fclean: clean
	@rm -rf $(OBJS)
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)
re: fclean all
