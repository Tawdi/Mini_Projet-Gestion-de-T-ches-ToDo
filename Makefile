# Define the compiler
CC = gcc

# Define the source files
SRC = main.c menu_fonctions.c fichier_fonctions.c ajoute_fonctions.c affiche_fonctions.c initiale_fonctions.c modifie_fonctions.c recherche_fonctions.c supprime_fonctions.c

# Create a list of object files by replacing .c with .o
OBJ = $(SRC:.c=.o)

# Default target
all: out run

# Rule to create object files from source files
%.o: %.c
	$(CC) -c -o $@ $<

# Rule to create the final executable
out: $(OBJ)
	$(CC) -o $@ $(OBJ)

# Rule to run the executable
run: out
	./out

# Rule to clean object files and the executable
clean:
	del *.o out

# #  Define the compiler
# CC = gcc

# SRC = main.c menu_fonctions.c fichier_fonctions.c ajoute_fonctions.c affiche_fonctions.c initiale_fonctions.c modifie_fonctions.c recherche_fonctions.c supprime_fonctions.c


# all: out run
    

# out: $(SRC)
# 	$(CC) -o out $(SRC) 

# run: out
# 	.\out

# clean:
# 	del -f *.o out
