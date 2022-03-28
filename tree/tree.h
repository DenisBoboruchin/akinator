#ifndef TREE
#define TREE

#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "../graphviz/graphviz.h"

const int           DESTROYSZ   =     -12323;

const int           NOMISTAKE   =          0;
const int           MISTAKE     =          1;
                                
const int           EMPTY       =       9234;
const int           NOTFOUND    =       -583;

enum comp
{
    LEFT    =       3523,
    RIGHT               ,
    EQUAL               ,
    NOCOMP
};

//-------------------------------------------------------------------------
//--------------------------TYPE_OF_THE_TREE-------------------------------
//-------------------------------------------------------------------------

#define STR
//typedef const char* ElemType;
                                                            
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
    int             CheckEmpty_ (struct item* prefItm);
    void            TreeDtor_   (struct item* node);

public:
    explicit        CTree       ();
                    ~CTree      ();

    int             addItm      (struct item* prefItm, ElemType data);
    struct item*    findItm     (ElemType data);

    int             graphDump   ();
};

int CtorElemsForDot (struct item* node);
int CtorEdgeForDot  (struct item* node);

int Compare         (ElemType data, ElemType object);

#endif
