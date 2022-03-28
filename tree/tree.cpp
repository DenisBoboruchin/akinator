#include "tree.h"

CTree::CTree () :
    treeRoot_ (nullptr),
    size_ (0) 
    {}
/*
CTree::~CTree ()
{
    
}

int CTree::delItm ()
{
    

    retrn NOMISTAKE;
}
*/

int CTree::addItm (struct item* prefItm, ElemType data)
{
    if (!treeRoot_)
    {
        treeRoot_ = new item;

        treeRoot_->data = data;

        return NOMISTAKE;
    }
    
    if ((prefItm->left) && (prefItm->right))
    {
        printf ("This item filled\n");

        return MISTAKE;
    }

    struct item* newItm = new item;
    
    newItm->data = data;
 
    if (Compare_ (data, prefItm->data) == LEFT)
        prefItm->left = newItm;

    else if (Compare_ (data, prefItm->data) == RIGHT)
        prefItm->right = newItm;

    else
        return MISTAKE;

    return NOMISTAKE;
}

int CTree::Compare_ (ElemType data, ElemType object)
{
    if (data > object)
        return RIGHT;
    else if (data <= object)
        return LEFT;

    return NOCOMP;
}

/*
struct item* CTree::findItm (ElemType data)
{
    struct item* item = treeRoot_; 

    while (item)
    {
        if (item->data == data)
            return item;
        //compare
    }
}*/
