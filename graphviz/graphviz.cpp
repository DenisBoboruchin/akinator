#include "graphviz.h"

static FILE* dotFile = fopen ("dump/dot.dot", "w");

void DotCtor (const char* rankdir, const char* color)
{
    //FILE* dotFile = fopen ("dump/dot.dot", "w");
    
    fprintf (dotFile, "digraph\n{\n");
    
    fprintf (dotFile, "\trankdir=%s;\n", rankdir);
    
    fprintf (dotFile, "\tgraph[bgcolor=darkseagreen2];\n");

    fprintf (dotFile, "\tnode[color=%s, fontsize = 8];\n", color);
}

void DotElemCtor (void* index, ElemType data, void* next, void* prev, const char* shape, 
        const char* color, const char* label, const char* style)
{
    fprintf (dotFile, "\t%s%p[shape=%s, ", label, index, shape); 
    fprintf (dotFile, "label=\"{<adress> addres\\n%p|<data> data\\n\\\"", index);
    fprintf (dotFile, ELEM_FMTS, data);
    
    fprintf (dotFile, "\\\"|{<left>left:%10p|<right>right:%10p}}\", ", next, prev);
    fprintf (dotFile, "fillcolor=\"%s\", style=%s];\n", color, style);
}
/*
void DotInfoElemCtor (int capacity, int size, int head, int tail, int free, int statLin, 
        const char* shape, const char* color, const char* style)
{
    fprintf (dotFile, "\t%s[shape=%s, ", "info", shape); 
    fprintf (dotFile, "label=\"Lists info|size:%4d|firstElem:\"",  
        capacity, size, head, tail, free, statLin);
    fprintf (dotFile, "fillcolor=\"%s\", style=%s];\n", color, style);
}*/

void DotLeftEdgeCtor (void* index1, void* index2, const char* style, const char* color)
{
    fprintf (dotFile, "\telem%p:<left>-> elem%p[style=%s, color=\"%s\"];\n", 
            index1, index2, style, color);
}

void DotRightEdgeCtor (void* index1, void* index2, const char* style, const char* color)
{
    fprintf (dotFile, "\telem%p:<right>-> elem%p[style=%s, color=\"%s\"];\n", 
            index1, index2, style, color);
}

void DotPrintf (const char* text, int num)
{
    fprintf (dotFile, "%s", text);

    if (num != -1)
        fprintf (dotFile, "%d", num);
}

void DotEnd (void)
{   
    fprintf (dotFile, "}\n\n");

    fclose (dotFile);

    system ("dot dump/dot.dot -Tpng -q -o dump/dump.png");
    system ("rm  dump/dot.dot");
}
