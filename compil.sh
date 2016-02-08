make -C ./libft/
gcc -g get_next_line.c -I ./libft/includes/ -L ./libft/ -lft
echo Compiled
echo Run get next line
./a.out file/test_file
