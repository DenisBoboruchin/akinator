#include "okenator.h"

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

int CTree::addItm (ElemType data)
{
    if (!treeRoot_)
    {
        treeRoot_ = new item;

        treeRoot_->data = data;

        return Nomistake;
    }
    
    struct item* newItem = findItm (data);
    newItem->data = data;

    return NOMISTAKE;
}

struct item* CTree::findItm (ElemType data)
{
    struct item* item = treeRoot_; 

    while (item)
    {
        if (item->data == data)
            return item;
        //compare
    }
}
