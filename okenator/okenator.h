#ifndef OKENATOR
#define OKENATOR

#include <stdio.h>

#include "../graphviz/graphviz.h"

const int           DESTROYSZ   =     -12323;

const int           NOMISTAKE   =          0;
const int           MISTAKE     =          1;
                                            
const int           NOTFOUND    =       -583;

typedef int ElemType;
                                                             
const int           DESTROYED   =      -1232;

struct item
{
	ElemType		data	    =	       0;

    struct item*	next	    =	 nullptr;
    struct item*    prev        =    nullptr;
};

class CTree
{
private:
	struct item*    treeRoot_   =    nullptr; 
    int             size_       =          0;

    int             TreeOk_               ();

public:
    explicit        CTree       ();
    //                ~CTree      ();

    int             addItm      (ElemType data);
    struct item*    findItm     (ElemType data);
};

#endif
