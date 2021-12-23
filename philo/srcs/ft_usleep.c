
#include "philosophers.h"

void    ft_usleep(unsigned long time_to_sleep)
{
    unsigned long time_to_reach = gettime() + time_to_sleep;
    while (gettime() < time_to_reach)
        usleep(10);
}
