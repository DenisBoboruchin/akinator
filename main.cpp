#include <stdio.h>

#include "akenator/akenator.h"

int main ()
{
    printf ("started\n");

    CTree t1;

    t1.addItm (nullptr, "root");

    t1.addItm (t1.findItm ("root"), "l1");
    t1.addItm (t1.findItm ("root"), "llll2");
    t1.addItm (t1.findItm ("l1"), "l");

    t1.graphDump ();

    return 0;
}
