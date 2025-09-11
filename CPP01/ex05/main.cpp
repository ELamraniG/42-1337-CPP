#include "Harl.hpp"

int main()
{

    int *a[4]; 
    a[0] = (int * )malloc(sizeof(int) * 4);
    Harl harlito;
    harlito.complain("DEBUG");
    harlito.complain("INFO");
    harlito.complain("WARNING");
    harlito.complain("ERROR");
    harlito.complain("just bs");
    return 0;
}