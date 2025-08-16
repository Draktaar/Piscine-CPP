make
make clean
clear

# failing tests
echo "Failing tests:\n"
./PmergeMe
./PmergeMe ""
./PmergeMe "4 2 3 1"
./PmergeMe 3 -4
./PmergeMe 3.0f 2 5
./PmergeMe 3.0 24 9.0
./PmergeMe a b c 1 2 3

#passing tests
echo "\nPassing tests:\n"
./PmergeMe 5 3
./PmergeMe 5 3 1
./PmergeMe 3 5 9 7 4
./PmergeMe 3 5 9 7 4 6 7 9 8 40
./PmergeMe 11 2 17 0 16 8 6 15 10 3 21 1 18 9 14 19 12 5 4 20 13 7


make fclean