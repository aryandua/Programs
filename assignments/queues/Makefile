gen:
	@echo "\n"
	@gcc randnumgen.c -o r.out
	@echo "Generating new testcase"
	@ ./r.out
	@echo "\n \n"
unord:
	@gcc queuearray_unordered.c -o u.out
	@echo "Running UnorderedArray \n"
	@time -p ./u.out
	@echo "Done"
	@echo "\n \n"	

ord:		
	@gcc queuearray_ordered.c -o o.out
	@echo "Running OrderedArray \n"
	@time -p ./o.out
	@echo "Done"
	@echo "\n \n"
ll:
	@gcc queuell.c -o l.out
	@echo "Running LinkedList \n"
	@time -p ./l.out
	@echo "Done"
	@echo "\n \n"
heap:
	@gcc queueheap.c -o h.out
	@echo "Running Heap \n"
	@time -p ./h.out
	@echo "Done"
	@echo "\n \n"
runall: gen unord ord ll heap
	spd-say Done
