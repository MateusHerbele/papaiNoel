parametrosCompilacao=-Wall 
nomePrograma=papainoel

all: $(nomePrograma)

$(nomePrograma): papainoel.o  
	gcc -o $(nomePrograma) papainoel.o $(parametrosCompilacao)

papainoel.o: papainoel.c
	gcc -c papainoel.c $(parametrosCompilacao)

clean:
	rm -f *.o *.gch $(nomePrograma)
