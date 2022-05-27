#Makefile de P0

VPATH = /home/poo/POO/Grondona_Nuño_Juanmanuel/Tests-auto:.
#//VPATH = ../Test-auto:.

#Compilador y opciones
CXX = clang++								  #Variable #Compilador de C++

CPPFLAGS = -I../Tests-auto -I. -DP0       #Variables de opciones del preprocesador
CXXFLAGS = -g -Wall -pedantic -std=c++11 #Variables de opciones del Compilador	
LDFFLAGS = 						  #Variables de opciones del enlazador

#Reglas del Makefile
all: test-P0-auto


test-P0-auto: test-caso0-fecha-auto.o test-caso0-cadena-auto.o \
			  test-auto.o cadena.o fecha.o #el \ sirve para que siga leyendo abajo
	$(CXX) -o $@ $(LDFLAGS) $^

test-caso0-fecha-auto.o test-caso0-cadena-auto.o test-auto.o: \
test-caso0-fecha-auto.cpp test-caso0-cadena-auto.cpp \
test-auto.cpp test-auto.hpp fecha.hpp cadena.hpp
	$(CXX) -c $(CXXFLAGS) $(CPPFLAGS) $^
	
fecha.o: fecha.hpp fecha.cpp
	$(CXX) -c $(CXXFLAGS) $(CPPFLAGS) $^
cadena.o: cadena.hpp cadena.cpp
	$(CXX) -c $(CXXFLAGS) $(CPPFLAGS) $^

clean: 
	$(RM) *.o test-P0-auto test-P0-consola
