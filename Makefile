NAME = push_swap

SOURCES = ft_radix.c \
	  ft_utils.c \
	  ft_utils_v2.c \
	  push_swap.c \
	  instructions.c \
	  ft_bb.c \

OBJECTS = $(SOURCES:.c=.o)

COMP = cc

COMP_FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

%.o: %.c
	$(COMP) $(COMP_FLAGS) -o $@ -c $<

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJECTS)

re: fclean all

.PHONY: fclean all clean re
