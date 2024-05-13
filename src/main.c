/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 21:49:57 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/05/13 15:31:57 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int main()
{
    mlx_t *mlx;
    mlx_image_t *img;

    mlx = mlx_init(900, 900, "so_long", false);
    if (!mlx)
        return(0);
   img = mlx_load_png("./image/oui.png");
   mlx_draw_image(mlx, img, 0, 0);
   mlx_loop(mlx);
    return(0);
}