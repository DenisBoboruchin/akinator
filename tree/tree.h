#ifndef TREE
#define TREE

#include <stdio.h>
#include <assert.h>

#include "../graphviz/graphviz.h"

const int           DESTROYSZ   =     -12323;

const int           NOMISTAKE   =          0;
const int           MISTAKE     =          1;
                                            
const int           NOTFOUND    =       -583;

const int           LEFT        =       3523;
const int           RIGHT       =       4923;
const int           NOCOMP      =       -296;

typedef int ElemType;
                                                             
const int           DESTROYED   =      -1232;

struct item
{
	ElemType		data	    =	       0;

    struct item*	left	    =	 nullptr;
    struct item*    right       =    nullptr;
};

class CTree
{
private:
	struct item*    treeRoot_   =    nullptr; 
    int             size_       =          0;

    int             TreeOk_     ();
    int             Compare_    (ElemType data, ElemType object);

public:
    explicit        CTree       ();
    //                ~CTree      ();

    int             addItm      (struct item* prefItm, ElemType data);
    struct item*    findItm     (ElemType data);
};

#endif
