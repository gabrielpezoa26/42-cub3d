#include <stdio.h>   // Para printf, fopen, fprintf
#include <stdlib.h>  // Para EXIT_FAILURE

void create_xpm_file(const char *filename, const char *color_char, const char *hex_color) {
    FILE *fp;
    int i, j;
    int width = 64;  // Largura padrão para Cub3D
    int height = 64; // Altura padrão para Cub3D

    // Tenta abrir o arquivo para escrita
    fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Erro ao criar o arquivo XPM");
        exit(EXIT_FAILURE); // Sai se não conseguir criar o arquivo
    }

    // Cabeçalho do XPM
    fprintf(fp, "/* XPM */\n");
    // O nome da variável C é baseado no nome do arquivo (sem o caminho)
    // Por exemplo, para "assets/no.xpm", o nome da variável pode ser "no_xpm"
    const char *var_name = filename;
    // Encontra o último '/' para pegar apenas o nome do arquivo
    const char *last_slash = filename;
    while (*last_slash != '\0') {
        if (*last_slash == '/') {
            var_name = last_slash + 1;
        }
        last_slash++;
    }
    // Remove a extensão .xpm
    char temp_var_name[128]; // Buffer temporário
    int len_var_name = 0;
    while (var_name[len_var_name] != '.' && var_name[len_var_name] != '\0' && len_var_name < 127) {
        temp_var_name[len_var_name] = var_name[len_var_name];
        len_var_name++;
    }
    temp_var_name[len_var_name] = '\0';

    fprintf(fp, "static char * %s_xpm[] = {\n", temp_var_name);

    // Linha de informações da imagem: "largura altura num_cores chars_por_pixel"
    fprintf(fp, "\"%d %d 1 1\",\n", width, height);

    // Definição da cor: "caractere c #HEX_COLOR"
    fprintf(fp, "\"%c c %s\",\n", *color_char, hex_color);

    // Dados dos pixels (linhas da imagem)
    i = 0;
    while (i < height) {
        fprintf(fp, "\""); // Início da linha de pixels
        j = 0;
        while (j < width) {
            fprintf(fp, "%c", *color_char); // Cada pixel é o caractere da cor
            j++;
        }
        fprintf(fp, "\""); // Fim da linha de pixels
        if (i < height - 1) { // Adiciona vírgula, exceto na última linha
            fprintf(fp, ",");
        }
        fprintf(fp, "\n"); // Quebra de linha
        i++;
    }
    fprintf(fp, "};\n"); // Fechamento do array de strings

    fclose(fp); // Fecha o arquivo
    printf("Arquivo XPM '%s' criado com sucesso!\n", filename);
}

int main(void) {
    // Certifique-se de que a pasta 'assets' existe no mesmo diretório do seu executável cub3D.
    // Se não existir, crie-a manualmente ou adicione `mkdir -p assets` no Makefile.

    // Textura Norte (NO) - Vermelha
    create_xpm_file("assets/no.xpm", "R", "#FF0000");

    // Textura Sul (SO) - Verde
    create_xpm_file("assets/so.xpm", "G", "#00FF00");

    // Textura Leste (EA) - Azul
    create_xpm_file("assets/ea.xpm", "B", "#0000FF");

    // Textura Oeste (WE) - Amarela
    create_xpm_file("assets/we.xpm", "Y", "#FFFF00");

    return (0);
}