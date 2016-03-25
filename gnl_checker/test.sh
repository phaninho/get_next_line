#!/bin/bash

echo "\033[33m--------------------------Norme--------------------------\033[0m"

norminette *.[ch]

echo "\033[33m-----------------------Préliminaires---------------------\033[0m"

if [ -f "../auteur" ]
then
	echo "\033[32mauteur found :\033[0m"
	cat -e ../auteur
else
	echo "\033[31mauteur not found\033[0m"
fi

if [ -f "../get_next_line.c" ]
then
	echo "\033[32mget_next_line.c found\033[0m"
else
	echo "\033[31mget_next_line.c not found\033[0m"
fi

if [ -f "../get_next_line.h" ]
then
	echo "\033[32mget_next_line.h found\033[0m"
else
	echo "\033[31mget_next_line.h not found\033[0m"
fi

echo "\033[33m\nVerification de la presence de BUFF_SIZE dans get_next_line.h\033[0m"
grep 'BUFF_SIZE' ../get_next_line.h
retval=$?
if [ "$retval" = 0 ]
then echo "\033[32mBUFF_SIZE found\n\033[0m"
else
echo "\033[31mBUFF_SIZE not found\n\033[0m"
fi
# end

echo "\033[33m--------------Verification contenue dossier--------------\033[0m"
cd ../
ls -la
cd gnl_checker


echo "\033[33m---------------------------TESTS-------------------------\033[0m"

sed -i '' 's/^\# define BUFF_SIZE.*/\# define BUFF_SIZE 8/' ../get_next_line.h
cat ../get_next_line.h
echo "\033[32m\nBUFF_SIZE defined to 8\033[0m\n"

make -C ../libft/ fclean && make -C ../libft/

echo "\033[32mCompilation gnl OK\033[0m"
gcc -Wall -Wextra -Werror -o gnl ./main.c ../get_next_line.c ../libft/libft.a
gcc -Wall -Wextra -Werror -o gnl2 ./main2.c ../get_next_line.c ../libft/libft.a

echo "\033[33m\n----------Verification fonction interdite--------------\033[0m"
nm -j ./gnl | cut -c 2-

#echo "\033[36m\n- Lire et retourner une ligne de 8 caractères terminée par un '\ n' inclus depuis l'entrée standard.\n\033[0m"
#echo -n "01234657" | ./gnl

echo "\033[33m\n--------------------Tests basiques---------------------\033[0m"

echo "\033[36m\n- Lire et retourner une ligne de 8 caractères terminée par un '\ n' inclus depuis un fichier.\033[0m"
./gnl fichiers_test/04_1_ligne_8_char_\\n | cat -e
echo "\033[36m\n- Lire et retourner deux lignes de 8 caractères terminée par un '\ n' inclus depuis un fichier.\033[0m"
./gnl fichiers_test/05_2_ligne_8_char_\\n | cat -e
echo "\033[36m\n- Lire et retourner un nombre quelconque de lignes de 8 caractères terminées par un '\ n' inclus depuis l'entrée standard.\033[0m"
./gnl fichiers_test/06_rand_ligne_8_char_\\n | cat -e

echo "\033[33m\n-----------------Tests intermédiaires------------------\033[0m"

echo "\033[36m\n- Lire et retourner une ligne de 16 caractères terminée par un '\ n' inclus depuis un fichier.\033[0m"
./gnl fichiers_test/07_1_ligne_16_char_\\n | cat -e
echo "\033[36m\n- Lire et retourner deux lignes de 16 caractères terminée par un '\ n' inclus depuis un fichier.\033[0m"
./gnl fichiers_test/08_2_ligne_16_char_\\n | cat -e
echo "\033[36m\n- Lire et retourner un nombre quelconque de lignes de 16 caractères terminées par un '\ n' inclus depuis l'entrée standard.\033[0m"
./gnl fichiers_test/09_rand_ligne_16_char_\\n | cat -e

echo "\033[33m\n--------------------Tests avancés----------------------\033[0m"

echo "\033[36m\n- Lire et retourner une ligne de 4 caractères terminée par un ' \ n' inclus depuis un fichier.\033[0m"
./gnl fichiers_test/13_1_ligne_4_char_\\n | cat -e
echo "\033[36m\n- Lire et retourner deux lignes de 4 caractères terminée par un ' \ n' inclus depuis un fichier.\033[0m"
./gnl fichiers_test/14_2_ligne_4_char_\\n | cat -e
echo "\033[36m\n- Lire et retourner un nombre quelconque de lignes de 4 caractères terminées par un '\ n' inclus depuis un fichier.\033[0m"
./gnl fichiers_test/15_rand_ligne_4_char_\\n | cat -e

echo "\033[36m\n- Lire et retourner une ligne de 4 caractères sans '\ n' depuis un fichier.\033[0m"
./gnl fichiers_test/19_1_ligne_4_char_\\n | cat -e
echo "\033[36m\n- Lire et retourner une ligne de 8 caractères sans '\ n' depuis un fichier.\033[0m"
./gnl fichiers_test/20_1_ligne_8_char_\\n | cat -e
echo "\033[36m\n- Lire et retourner une ligne de 16 caractères sans '\ n' depuis un fichier.\033[0m"
./gnl fichiers_test/21_1_ligne_16_char_\\n | cat -e

echo "\033[36m\n- Lire et retourner une ligne vide depuis un fichier.\033[0m"
./gnl fichiers_test/22_ligne_vide | cat -e

echo "\033[33m\n--------------------Gestion d'erreur----------------------\033[0m"

echo "\033[36m\n- Passer un descripteur de fichier arbitraire à la fonction get_next_line sur lequel il n'est pas possible de lire, par exemple 42. La fonction doit retourner -1.\033[0m"

./gnl2 fichiers_test/04_1_ligne_8_char_\\n | cat -e

echo "\033[36m\n- Mettre BUFF_SIZE à 1, 32, 9999 puis 10000000. Le dernier cas peut ne pas fonctionner (et ne doit pas compter comme une erreur dans cette soutenance). L'un de vous deux sait-il pourquoi ?\033[0m"

echo "\033[32m\n------------------BUFF_SIZE 1--------------------------\033[0m"

sed -i '' 's/^\# define BUFF_SIZE.*/\# define BUFF_SIZE 1/' ../get_next_line.h
cat ../get_next_line.h
echo "\033[32m-------------------------------------------------------\033[0m\n"
./gnl fichiers_test/04_1_ligne_8_char_\\n | cat -e

echo "\033[32m\n------------------BUFF_SIZE 32--------------------------\033[0m"

sed -i '' 's/^\# define BUFF_SIZE.*/\# define BUFF_SIZE 32/' ../get_next_line.h
cat ../get_next_line.h
echo "\033[32m-------------------------------------------------------\033[0m\n"
./gnl fichiers_test/04_1_ligne_8_char_\\n | cat -e

echo "\033[32m\n------------------BUFF_SIZE 9999--------------------------\033[0m"

sed -i '' 's/^\# define BUFF_SIZE.*/\# define BUFF_SIZE 9999/' ../get_next_line.h
cat ../get_next_line.h
echo "\033[32m-------------------------------------------------------\033[0m\n"
./gnl fichiers_test/04_1_ligne_8_char_\\n | cat -e

echo "\033[32m\n------------------BUFF_SIZE 10000000--------------------------\033[0m"

sed -i '' 's/^\# define BUFF_SIZE.*/\# define BUFF_SIZE 10000000/' ../get_next_line.h
cat ../get_next_line.h
echo "\033[32m-------------------------------------------------------\033[0m\n"
./gnl fichiers_test/04_1_ligne_8_char_\\n | cat -e

rm ./gnl ./gnl2
