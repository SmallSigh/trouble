// void    print_fiercly(){ft_printf("fiercly");}
// void    print_malicious(){ft_printf("with malicious intent");}
// void    print_accidently(){ft_printf("accidently");}
// void    print_strong_hit(){ft_printf("with a strong hit");}
// void    print_low_blow(){ft_printf("with a low blow");}
// void    print_spits(){ft_printf("and spits in their face");}
// void    print_smooch(){ft_printf("and gives a little smooch on the cheek");}
// void    print_explanation(){ft_printf("and hopes they will listen to their my_alloc is better then ft_alloc");}

#include "main_header.h"

const char *random_word()
{
    int i;

    i = my_random(1, 8);
    static const char   *words[8];
    words[1] = "fiercly";
    words[2] = "with malicious intent";
    words[3] = "accidently";
    words[4] = "with a strong hit";
    words[5] = "with a low blow";
    words[6] = "and spits in their face";
    words[7] = "and gives a little smooch on the cheek";
    words[8] = "and hopes they will listen to their my_alloc is better then ft_alloc";
    return (words[i]);
}
