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

const int           STARTNUM    =          7;

const int           MAXANSWSIZE =         50;

enum addMode
{
    ADDLEFT     =    123,
    ADDRIGHT            ,
    STANDART
};

enum comp
{
    LEFT        =   3523,
    RIGHT               ,
    EQUAL               ,
    NOCOMP
};

//-------------------------------------------------------------------------
//--------------------------TYPE_OF_THE_TREE-------------------------------
//-------------------------------------------------------------------------
//#define ELEM_FMT "%s"
#define STR
//typedef const char* ElemType;
                                                            
struct item
{
	ElemType		data	    =	       0;

    struct item*    parent      =    nullptr;

    struct item*	left	    =	 nullptr;
    struct item*    right       =    nullptr;
};

struct buf
{
    char*           buffer_     =    nullptr;
    char*           buffForNew  =    nullptr;
    int             counter     =          0;
};

class CTree
{
private:
	struct item*    treeRoot_   =    nullptr; 
    int             size_       =          0;

    int             TreeOk_             ();
    int             CheckEmpty_         (struct item* prefItm);
    void            TreeDtor_           (struct item* node);
    int             CompareAndAddItm_   (struct item* prefI, struct item* newI);

public:
    struct buf      buff        =         {};
    
    explicit        CTree               ();
                    ~CTree              ();

                    CTree               (const CTree& obj);

    struct item*    addItm              (struct item* prefItm, ElemType data, int mode = STANDART);
    struct item*    findItm             (ElemType data);

    void            addBuffer           (char* buffer);

    item*           root                ();
    int             graphDump           ();
};

int CtorElemsForDot             (struct item* node);
int CtorEdgeForDot              (struct item* node);

int Compare                     (ElemType data, ElemType object);

//#undef ELEM_FMT

#endif
