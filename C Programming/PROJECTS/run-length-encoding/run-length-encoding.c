#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compress(FILE* input, FILE* output) {
  int curr_char = fgetc(input);
  if (curr_char == EOF)
    return;

  int len = 1;
  int next_char;

  while ((next_char = fgetc(input)) != EOF) {
    if (next_char == curr_char && len < 255) {
      len++; 
    }
    else {
      fputc(curr_char, output);
      fputc(len, output);

      curr_char = next_char;
      len = 1;
    }
  }

  fputc(curr_char, output);
  fputc(len, output);
}

void decompress(FILE* input, FILE* output) {
  do {
    int ch = fgetc(input);
    if (ch == EOF) break;

    int len = fgetc(input);
    if (len == EOF) {
      fprintf(stderr, "Corrupted compressed file.\n"); // think about it 
      break;
    }

    for (int i = 0; i < len; i++) {
      fputc(ch, output);
    }
  } while (1);
}

int main(int argc, char* argv[]) {
  if (argc != 4) {
    printf("Usage: %s [compress | decompress] <source_file> <destination_file>\n", argv[0]);
    exit(-1);
  }

  FILE* input = fopen(argv[2], "rb");
  if (input == NULL) {
    printf("Error opening source file.\n");
    exit(-1);
  }

  FILE* output = fopen(argv[3], "wb");
  if (output == NULL) {
    printf("Error opening destination file.\n");
    exit(EXIT_FAILURE);
  }

  if (!strcmp(argv[1], "compress")) {
    compress(input, output);
  }
  else if (!strcmp(argv[1], "decompress")) {
    decompress(input, output);
  }
  else {
    printf("Usage: %s [compress | decompress] <source_file> <destination_file>\n", argv[0]);
    fclose(input);
    fclose(output);
    exit(EXIT_FAILURE);
  }

  fclose(input);
  fclose(output);

  return EXIT_SUCCESS;
}
