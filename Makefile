NAME =	libasm
ASMS =	ft_read.s \
		ft_write.s \
		ft_strlen.s \
		ft_strcmp.s \
		ft_strcpy.s \
		ft_strdup.s
OBJS =	$(ASMS:.s=.o)
CC	 =	gcc
NASM =  nasm -f macho64
all: $(NAME)
%.o: %.s libasm.h
	$(NASM) $< -o $@
test: $(NAME)
	@echo 1243236547586 >> test.txt
	gcc main.c -I. -L. -lasm -o $(NAME)
$(NAME): $(OBJS)
	@ar rcs $(NAME).a $(OBJS)
clean:
	@rm -f $(OBJS)
fclean: clean
	@rm -f $(NAME).a
	@rm -f $(NAME)
	@rm -f test.txt
re: fclean all
.PHONY: all clean fclean re $(NAME)