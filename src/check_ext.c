#include "so_long.h"

char *strchrmod(char *s, char* target)
{
    int i;

    i = 0;
    while (s[i])
    {
        if (strcmp(s + i, target) == 0)
            return (s + i);
        i++;
    }
    return (NULL);
}
int is_valid(char *str)
{
    if (strchrmod(str, ".ber"))
        return (1);
    else
    {
        ft_printf("Error\n Your map is not a .ber !\n");
        return (0);
    }
}
