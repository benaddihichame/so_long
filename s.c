// void    event_listener(mlx_key_data_t keydata, void* param)
// {
//     t_game *game;
//     game = (t_game *)param;
//     int y = game->y;
//     int x = game->x;
//     if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
//         mlx_close_window(game->mlx);
//     if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE && game->map[y - 1][x] != '1')
//     {
//         if (game->map[y - 1][x] == 'C')
//             grab_pokeball(game, x , y - 1);
//         game->y--;
//     }
//     else if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE && game->map[y + 1][x] != '1')
//     {
//         if (game->map[y + 1][x] == 'C')
//             grab_pokeball(game, x , y + 1);
//         game->y++;
//     }
//     else if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE && game->map[y][x - 1] != '1')
//     {
//         if (game->map[y][x - 1] == 'C')
//             grab_pokeball(game, x - 1 , y);
//         game->x--;
//     }
//     else if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE && game->map[y][x + 1] != '1')
//     {
//         if(game->map[y][x + 1] == 'C')
//             grab_pokeball(game, x + 1 , y);
//         game->x++;
//     }
//     if (game->x != x || game->y != y)
//     {
//             game->step++;
//             ft_printf("You mooved : %d Time\n", game->step);
//             game->tab_png[3].img->instances[0].x = game->x * PIXEL;
//             game->tab_png[3].img->instances[0].y = game->y * PIXEL;
//             //display(game);
//     }
// }