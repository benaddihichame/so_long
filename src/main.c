/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 21:49:57 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/05/13 15:42:44 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int main()
{
    mlx_t *mlx;
    mlx_image_t *img;
    mlx_texture_t *texture;

    mlx = mlx_init(900, 900, "so_long", false);
    if (!mlx)
        return(0);
    img = mlx_load_png("./image/oui.png");
    texture = mlx_texture_to_image(mlx, img);
    mlx_image_to_window(mlx, texture, 0, 0);
    mlx_resize_image(texture, 32, 32);
    mlx_loop(mlx);
    return(0);
}