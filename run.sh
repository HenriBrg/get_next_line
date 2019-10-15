gcc -Wall -Wextra -Werror -o gnl -D BUFFER_SIZE=8 main.c get_next_line.c get_next_line_utils.c

if [ ! -f gnl ]; then
	echo "Erreur durant la compilation"
	exit
fi

declare -a srcFiles=( "srcFilesTest/4-one" "srcFilesTest/4-one-n"
					  "srcFilesTest/4-two" "srcFilesTest/4-three"
					  "srcFilesTest/16-one"  "srcFilesTest/16-one-n"
					  "srcFilesTest/16-two"  "srcFilesTest/16-three"
					  "srcFilesTest/16-five" "srcFilesTest/hello"
					  "srcFilesTest/easy"    "srcFilesTest/this_is_a_file"
					  "srcFilesTest/empty"   "srcFilesTest/one_blank_line"
					  "srcFilesTest/empty_line_then_char"
					  "srcFilesTest/two_blank_lines" "srcFilesTest/libft_catted"
					  "srcFilesTest/moulinetter" "srcFilesTest/moulinetter2"
					  "srcFilesTest/long_line_easy" "srcFilesTest/long_line"
					  "srcFilesTest/long_line_three"
					  "srcFilesTest/long_lines_same_length"
					  "srcFilesTest/factbook")


try () {
	./gnl $1
	# echo "--- Test du fichier" $1
	# cat tmpCompare
	# echo "***"
	# cat $1
	# echo "***"
	# cmp --silent $1 tmpCompare && echo "Success : " $1 cut || echo "------ > FAIL" $1 # Avec double messages
	cmp --silent $1 tmpCompare || echo "GNL failed on" $1 # Avec double messages

	echo "" > tmpCompare
}

for file in ${srcFiles[@]}
do
	try $file
done
