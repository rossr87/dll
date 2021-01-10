target:application.exe

application.exe:main.o ldll.a
	gcc main.o -o application.exe -L . ldll.a
main.o:main.c
	gcc -c main.c -o main.o
ldll.a:dll.o dll_utils.o
	ar rs ldll.a dll.o dll_utils.o
dll.o:dll.c
	gcc -c dll.c -o dll.o
dll_utils.o:dll_utils.c
	gcc -c dll_utils.c -o dll_utils.o
clean:
	rm main.o
	rm ldll.a
	rm dll.o
	rm dll_utils.o
