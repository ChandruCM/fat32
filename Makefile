out.exe: main.c assign.c cluster_start.c read_info.c long_name.c
	gcc -Wall $^ -o $@
clean:
	rm *.exe
