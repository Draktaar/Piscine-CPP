make
make clean
clear

# failing tests
echo "Failing tests:"
./RPN
./RPN ""
./RPN "213" "324"
./RPN lkjjh
./RPN "+ 8 3 /"
./RPN "1 2"
./RPN "8 0 /"

#passing tests
echo "\n\nPassing tests:"
./RPN 1
./RPN "1"
./RPN "1 2 +"
./RPN "1 2 -"
./RPN "9 8 *"
./RPN "8 3 /"

#tests from subject
echo "\n\nTests from subject:"
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
./RPN "7 7 * 7 -"
./RPN "1 2 * 2 / 2 * 2 4 - +"
./RPN "(1 + 1)"

make fclean