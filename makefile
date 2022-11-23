serviceapp: home_service_app_main.o home_service_app_menu.o home_service_app_func1.o home_service_app_func2.o
	gcc -o serviceapp home_service_app_main.o  home_service_app_menu.o home_service_app_func1.o home_service_app_func2.o

home_service_app_main.o: home_service_app_main.c home_service_app_header.h
	gcc -o home_service_app_main.o -c home_service_app_main.c

home_service_app_menu.o: home_service_app_menu.c home_service_app_header.h
	gcc -o home_service_app_menu.o -c home_service_app_menu.c

home_service_app_func1.o: home_service_app_func1.c home_service_app_header.h
	gcc -o home_service_app_func1.o -c home_service_app_func1.c

home_service_app_func2.o: home_service_app_func2.c home_service_app_header.h
	gcc -o home_service_app_func2.o -c home_service_app_func2.c
clean:
	rm *.o
