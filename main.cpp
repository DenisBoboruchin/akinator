#include <stdio.h>

#include "akinator/akinator.h"

int main ()
{
    printf ("started\n");

    CTree t1;

    t1.addItm (nullptr, "Животное?");

    t1.addItm (t1.findItm ("Животное?"), "кот               ");
    t1.addItm (t1.findItm ("Животное?"), "Фачит?");
    t1.addItm (t1.findItm ("Фачит?"), "Млад?");

    t1.addItm (t1.findItm ("Млад?"), "U");
    t1.addItm (t1.findItm ("Млад?"), "T           ");
   
    t1.addItm (t1.findItm ("Фачит?"), "P                ");


    FILE* file = fopen ("dump/treeListing.txt", "w");

    CtorTreeListing (file, t1.findItm ("Животное?"));

    t1.graphDump ();

    return 0;
}
