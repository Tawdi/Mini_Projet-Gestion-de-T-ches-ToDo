# # Define the compiler
# CC = gcc

# # Define the source files
# SRC = main.c menu_fonctions.c fichier_fonctions.c ajoute_fonctions.c affiche_fonctions.c initiale_fonctions.c modifie_fonctions.c recherche_fonctions.c supprime_fonctions.c statistiques_fonctions.c

# # Create a list of object files by replacing .c with .o
# OBJ = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC))

# OBJ_DIR = object_files

# # Default target
# all: $(OBJ_DIR)/out


# # Rule to create object files from source files
# # Rule to create object files from source files
# $(OBJ_DIR)/%.o: %.c
# 	@mkdir -p $(OBJ_DIR)
# 	$(CC) -c -o $@ $<

# # Rule to create the final executable
# $(OBJ_DIR)/out: $(OBJ)
# 	$(CC) -o $@ $(OBJ)

# # Rule to run the executable
# run: $(OBJ_DIR)/out
# 	./$(OBJ_DIR)/out

# # Rule to clean object files and the executable
# clean:
#     rm -f $(OBJ_DIR)/*.o $(OBJ_DIR)/out


# # #  Define the compiler
# # CC = gcc

# # SRC = main.c menu_fonctions.c fichier_fonctions.c ajoute_fonctions.c affiche_fonctions.c initiale_fonctions.c modifie_fonctions.c recherche_fonctions.c supprime_fonctions.c


# # all: out run
    

# # out: $(SRC)
# # 	$(CC) -o out $(SRC) 

# # run: out
# # 	.\out

# # clean:
# # 	del -f *.o out
# Define the compiler
CC = gcc

# Define the source files
SRC = main.c menu_fonctions.c fichier_fonctions.c ajoute_fonctions.c \
       affiche_fonctions.c modifie_fonctions.c \
       recherche_fonctions.c supprime_fonctions.c statistiques_fonctions.c tri_fonctions.c

# Create a list of object files by replacing .c with .o and prepending the object directory
OBJ = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC))

# Define the object file directory
OBJ_DIR = object_files

# Default target
all: out run

# Rule to create object files from source files
$(OBJ_DIR)/%.o: %.c
	
	$(CC) -c -o $@ $<

# Rule to create the final executable
out: $(OBJ)
	$(CC) -o $@ $(OBJ)

# Rule to run the executable
run: out
	.\out

# Rule to clean object files and the executable
clean: 
	@del /Q $(OBJ_DIR)\*.o 2>nul || echo No object files to delete
	@del /Q out.exe 2>nul || echo No executable to delete
