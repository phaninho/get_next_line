make -C ./libft/
gcc -g -Wall -Wextra -Werror get_next_line.c main.c -I ./libft/includes/ -L ./libft/ -lft
echo Compiled
echo Run get next line
./a.out ../Test_files_42/42FileChecker/srcs/gnl/gnl10.txt
