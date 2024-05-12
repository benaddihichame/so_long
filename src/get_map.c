#include "../so_long.h"

// cette fonction permet de compter le nombre de ligne dans le fichier

int count_line(char *file_name)
{
    int fd;
    int i;
    char *line;

    i = 0;
    fd = open(file_name, O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
        i++;
    close(fd);
    return (i);
}
//cette fonction permet de recuperer la map dans un tableau de chaine de caractere
void get_map(char *file_name, t_game *game)
{
    int fd;
    int i;
    char *line;

    i = 0;
    game->map = malloc((count_line(file_name) + 1) * sizeof(char *));
    fd = open(file_name, O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        game->map[i] = line;
        i++;
    }
    close(fd);
    game->map[i] = NULL;
}