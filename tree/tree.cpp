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
 
    switch (Compare (data, prefItm->data))
    {
        case LEFT:
            prefItm->left = newItm;
            break;

        case RIGHT:
            prefItm->right = newItm;
            break;

        default:
            printf ("ERROR!!! Compare error!\n");
            return MISTAKE;
    }
    
    return NOMISTAKE;
}

int Compare (ElemType data, ElemType object)
{
    if (data > object)
        return RIGHT;
    else if (data < object)
        return LEFT;
    else if (data == object)
        return EQUAL;

    return NOCOMP;
}

int CTree::graphDump ()
{
    DotCtor ("TB", "darkkhaki");

    CtorElemsForDot (treeRoot_);

    CtorEdgeForDot (treeRoot_);

    DotEnd ();

    return NOMISTAKE;
}

int CtorElemsForDot (struct item* node)
{
    assert (node != nullptr);

    DotElemCtor (node, node->data, node->left, node->right);

    if (node->left)
        CtorElemsForDot (node->left);
    if (node->right)
        CtorElemsForDot (node->right);

    return NOMISTAKE;
}

int CtorEdgeForDot (struct item* node)
{
    assert (node != nullptr);

    if (node->left)
    {
        DotLeftEdgeCtor (node, node->left);

        CtorEdgeForDot (node->left);
    }
    
    if (node->right)
    {
        DotRightEdgeCtor (node, node->right);

        CtorEdgeForDot (node->right);
    }

    return NOMISTAKE;
}

struct item* CTree::findItm (ElemType data)
{
    struct item* item = treeRoot_; 

    while (item)
    {
        switch (Compare (data, item->data))
        {
            case LEFT:
                item = item->left;
                break;

            case RIGHT:
                item = item->right;
                break;

            case EQUAL:
                return item;
                
            default:
                printf ("ERROR!!! Compare error!\n");
                break;
        }
    }

    return nullptr;
}
