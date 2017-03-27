
OBJS="word.o matcher.o"

rm word_test
rm search
rm $OBJS

make $OBJS
make word_test.o
make matcher_test.o
make search.o

gcc -lstdc++ -o word_test word_test.o $OBJS 
gcc -lstdc++ -o matcher_test matcher_test.o $OBJS 

gcc -lstdc++ -o search search.o $OBJS

# ./word_test

