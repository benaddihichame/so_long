#include <string.h>
#include "../include/so_long.h"

int	is_wall(t_game *game)
{
	int	i;
	int	j;
	int	height;

	i = 0;
	while (game->map[0][i])
	{
		if (game->map[0][i++] != '1')
			return (FALSE);
	}
	i = 0;
	while (game->map[++i])
	{
		if (game->map[i][0] != '1' ||
			game->map[i][strlen(game->map[i]) - 1] != '1')
			return (FALSE);
	}
	height = i - 1;
	j = 0;
	while (game->map[height][j])
	{
		if (game->map[height][j++] != '1')
			return (FALSE);
	}
	return (TRUE);
}

int main(void)
{
    // Exemple de carte de jeu
    char *map[] = {
        "11111111111111111111111111",
        "10000000000000000000000001",
        "10000000000000000000000001",
        "11111111111111111111111111",
        NULL
    };

    t_game game;
    game.map = map;

    if (is_wall(&game) == TRUE)
    {
        printf("La carte est entourée de murs.\n");
    }
    else
    {
        printf("La carte n'est pas correctement entourée de murs.\n");
    }

    return 0;
}