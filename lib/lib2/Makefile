.PHONY:clean

OBJ=add.o\
    sub.o

a.out:test.o libmymath.a
	gcc $< -o $@ -L . -lmymath

libmymath.a:$(OBJ)
	ar -cr $@ $^

%.o:%.c
	gcc -c $< -o $@

clean:

	rm -f *.o


