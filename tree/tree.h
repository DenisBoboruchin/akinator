#ifndef TREE
#define TREE

#include <stdio.h>
#include <assert.h>

#include "../graphviz/graphviz.h"

const int           DESTROYSZ   =     -12323;

const int           NOMISTAKE   =          0;
const int           MISTAKE     =          1;
                                            
const int           NOTFOUND    =       -583;

enum comp
{
    LEFT    =       3523,
    RIGHT               ,
    EQUAL               ,
    NOCOMP
};

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

public:
    explicit        CTree       ();
    //                ~CTree      ();

    int             addItm      (struct item* prefItm, ElemType data);
    struct item*    findItm     (ElemType data);

    int             graphDump   ();
};

int CtorElemsForDot (struct item* node);
int CtorEdgeForDot  (struct item* node);

int Compare         (ElemType data, ElemType object);

#endif
