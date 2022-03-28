#include <stdio.h>

#include "akenator/akenator.h"

int main ()
{
    printf ("started\n");

    CTree t1;

    t1.addItm (nullptr, 2);

    t1.addItm (t1.findItm (2), 3);
    t1.addItm (t1.findItm (2), 1);
    t1.addItm (t1.findItm (1), 0);
    t1.addItm (t1.findItm (1), 2);
    t1.addItm (t1.findItm (3), 2);

    t1.graphDump ();

    return 0;
}
