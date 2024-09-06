// ************************************************

// fputc() : Writes a single character to a file.
// fputs(): Writes a string to a file.
// fprintf(): Writes a formatted string (data) to a file.

// int fputs(const char *s, FILE *fp);

// int fprintf(FILE *stream, const char *format [, argument, ...])

// ************************************************

// fgetc(): Reads a single character from a file.
// fgets(): Reads a string from a file.
// fscanf(): Reads a formatted string from a file.

// int fgetc(FILE * fp);

// int fscanf(FILE *stream, const char *format, ...)

// ************************************************

// FILE *fopen(const char *filename, const char *mode);
// todo_file = fopen("tache_list.txt", "a");
// todo_file = fopen("tache_list.txt", "w");
// todo_file = fopen("tache_list.txt", "r");


// fwrite(*buffer, size, no, FILE);
// fread(*buffer, size, no, FILE);