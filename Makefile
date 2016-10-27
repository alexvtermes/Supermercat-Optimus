all:program Client Producte Cjt_productes Cjt_clients Supermercat
	
program:program.cc
	g++ -c program.cc -D_JUDGE_ -D_GLIBCXX_DEBUG -ansi -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++0x

Client:Client.cc
	g++ -c Client.cc -D_JUDGE_ -D_GLIBCXX_DEBUG -ansi -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++0x
	
Producte:Producte.cc
	g++ -c Producte.cc -D_JUDGE_ -D_GLIBCXX_DEBUG -ansi -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++0x
	
Cjt_productes:Cjt_productes.cc
	g++ -c Cjt_productes.cc -D_JUDGE_ -D_GLIBCXX_DEBUG -ansi -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++0x
	
Cjt_clients:Cjt_clients.cc
	g++ -c Cjt_clients.cc -D_JUDGE_ -D_GLIBCXX_DEBUG -ansi -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++0x
	
Supermercat:Supermercat.cc
	g++ -c Supermercat.cc -D_JUDGE_ -D_GLIBCXX_DEBUG -ansi -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++0x
	
program.exe:program.o Client.o Producte.o Cjt_productes.o Cjt_clients.o Supermercat.o
	g++ -o program.exe program.o Client.o Producte.o Cjt_productes.o Cjt_clients.o Supermercat.o
	
practica.tar:program.cc Cjt_clients.cc Cjt_clients.hh Client.cc Client.hh Cjt_productes.cc Cjt_productes.hh Producte.cc Producte.hh Supermercat.cc Supermercat.hh jp_alex.vinas.est.fib.upc.edu_entrada.txt jp_alex.vinas.est.fib.upc.edu_sortida.txt jp_alvaro.antonio.gil.est.fib.upc.edu_entrada.txt jp_alvaro.antonio.gil.est.fib.upc.edu_sortida.txt equip.pdf html.zip Makefile
	tar -cvf practica.tar program.cc Cjt_clients.cc Cjt_clients.hh Client.cc Client.hh Cjt_productes.cc Cjt_productes.hh Producte.cc Producte.hh Supermercat.cc Supermercat.hh jp_alex.vinas.est.fib.upc.edu_entrada.txt jp_alex.vinas.est.fib.upc.edu_sortida.txt jp_alvaro.antonio.gil.est.fib.upc.edu_entrada.txt jp_alvaro.antonio.gil.est.fib.upc.edu_sortida.txt equip.pdf html.zip Makefile

clean:
	rm -f *.o program Client Producte Cjt_productes Cjt_clients Supermercat
