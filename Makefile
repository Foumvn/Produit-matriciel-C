                  

produit_matriciel:produit_matriciel.h  main.c  produit_matriciel.c
		gcc -o produit_matriciel main.c produit_matriciel.c -lpthread
run:
	./produit_matriciel  100
clean:
	rm  produit_matriciel 
