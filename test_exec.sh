clang -std=c11 -Wall gitm.c -o gitm
# diff -w ./tests/term.out <(./gitm < ./tests/term.in)
# ./gitm < ./tests/place_invalid.in
#./gitm < ./tests/history_check.in

#inputs of the cases:
# ./gitm < ./tests/horizontal_basic.in
# ./gitm < ./tests/vertical_basic.in
# ./gitm < ./tests/term.in
# ./gitm < ./tests/diagonal_test_1.in
# ./gitm < ./tests/who_basic.in
# ./gitm < ./tests/resign_test.in
# ./gitm < ./tests/history_check.in
# ./gitm < ./tests/view_basic.in


#./gitm < ./tests/invalid_space.in
#./gitm < ./tests/white_victory.in

#./gitm < ./tests/long_rubbish.in

#below are working cases:

#basic tests:
diff ./tests/horizontal_basic.out <(./gitm < ./tests/horizontal_basic.in)
diff ./tests/vertical_basic.out <(./gitm < ./tests/vertical_basic.in)
diff ./tests/term.out <(./gitm < ./tests/term.in)
diff ./tests/diagonal_test_1.out <(./gitm < ./tests/diagonal_test_1.in)
diff ./tests/who_basic.out <(./gitm < ./tests/who_basic.in)
diff ./tests/resign_basic.out <(./gitm < ./tests/resign_basic.in)
diff ./tests/history_check.out <(./gitm < ./tests/history_check.in)
diff ./tests/view_basic.out <(./gitm < ./tests/view_basic.in)
diff ./tests/white_victory.out <(./gitm < ./tests/white_victory.in)

diff ./tests/resign_basic.out <(./gitm < ./tests/resign_basic.in)

#Invalid tests:
diff ./tests/invalid_space.out <(./gitm < ./tests/invalid_space.in)
diff ./tests/long_rubbish.out <(./gitm < ./tests/long_rubbish.in)

