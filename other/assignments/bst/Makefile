run:
	gcc tcgen.c -o b.out
	./b.out
	gcc bst.c
	./a.out testcase.txt 0 101
	diff check1.txt check2.txt > /dev/null 
	echo $?
