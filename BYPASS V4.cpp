#include "MemoryTools.h"
int main(int argc,char **argv)
{
    char *bm;
    int gs;
    int pkg_pubg;
    int pkg_korea;
    int pkg_lite;

    pkg_korea = isapkrunning("com.pubg.krmobile");
    pkg_lite = isapkrunning("com.tencent.iglite");
    pkg_pubg = isapkrunning("com.tencent.ig");

    if (pkg_korea == 1)
    {
        bm = "com.pubg.krmobile";
    }
    else if (pkg_lite == 1)
    {
        bm = "com.tencent.iglite";
    }
    else
    {
        if (pkg_pubg != 1)
        {
            puts("PUBG IS NOT RUNNING");
            return 0;
        }

        bm = "com.tencent.ig";
    }

killGG();
 
void *jg;

BypassGameSafe();
for(int i=0;i<=6000;i++)
{
    SetSearchRange(C_ALLOC);
    MemorySearch(bm,"131330",&gs,DWORD);
    PMAPS GetResults();
    MemoryWrite(bm,"0",0,DWORD);
    PMAPS GetResults();
    AddFreezeItem_All(bm,"0",DWORD,0);
    StartFreeze(bm);
    SetFreezeDelay(0);
    PrintFreezeItems();
    ClearResults();     
}
BypassGameSafe();
for(int i=0;i<=6000;i++)
{
    SetSearchRange(C_ALLOC);
    MemorySearch(bm,"133378",&gs,DWORD);
    PMAPS GetResults();
    MemoryWrite(bm,"0",0,DWORD);
    PMAPS GetResults();
    AddFreezeItem_All(bm,"0",DWORD,0);
    StartFreeze(bm);
    SetFreezeDelay(0);
    PrintFreezeItems();
    ClearResults();
}
BypassGameSafe();
for(int i=0;i<=6000;i++)
{
    SetSearchRange(C_ALLOC);
    MemorySearch(bm,"66306",&gs,DWORD);
    PMAPS GetResults();
    MemoryWrite(bm,"0",0,DWORD);
    PMAPS GetResults();
    AddFreezeItem_All(bm,"0",DWORD,0);
    StartFreeze(bm);
    SetFreezeDelay(0);
    PrintFreezeItems();
    ClearResults();
}
BypassGameSafe();
for(int i=0;i<=6000;i++)
{
    SetSearchRange(C_ALLOC);
    MemorySearch(bm,"263170",&gs,DWORD);
    PMAPS GetResults();
    MemoryWrite(bm,"0",0,DWORD);
    PMAPS GetResults();
    AddFreezeItem_All(bm,"0",DWORD,0);
    StartFreeze(bm);
    SetFreezeDelay(0);
    PrintFreezeItems();
    ClearResults();
}
BypassGameSafe();
for(int i=0;i<=6000;i++)
{
    SetSearchRange(C_ALLOC);
    MemorySearch(bm,"134658",&gs,DWORD);
    PMAPS GetResults();
    MemoryWrite(bm,"0",0,DWORD);
    PMAPS GetResults();
    AddFreezeItem_All(bm,"0",DWORD,0);
    StartFreeze(bm);
    SetFreezeDelay(0);
    PrintFreezeItems();
    ClearResults();
}
BypassGameSafe();
for(int i=0;i<=6000;i++)
{
    SetSearchRange(C_ALLOC);
    MemorySearch(bm,"135682",&gs,DWORD);
    PMAPS GetResults();
    MemoryWrite(bm,"0",0,DWORD);
    PMAPS GetResults();
    AddFreezeItem_All(bm,"0",DWORD,0);
    StartFreeze(bm);
    SetFreezeDelay(0);
    PrintFreezeItems();
    ClearResults();
}
BypassGameSafe();
for(int i=0;i<=6000;i++)
{
    SetSearchRange(C_ALLOC);
    MemorySearch(bm,"4096",&gs,DWORD);
    PMAPS GetResults();
    MemoryWrite(bm,"0",0,DWORD);
    PMAPS GetResults();
    AddFreezeItem_All(bm,"0",DWORD,0);
    StartFreeze(bm);
    SetFreezeDelay(0);
    PrintFreezeItems();
    ClearResults();
}
BypassGameSafe();
for(int i=0;i<=6000;i++)
{
    SetSearchRange(C_ALLOC);
    MemorySearch(bm,"134914",&gs,DWORD);
    PMAPS GetResults();
    MemoryWrite(bm,"0",0,DWORD);
    PMAPS GetResults();
    AddFreezeItem_All(bm,"0",DWORD,0);
    StartFreeze(bm);
    SetFreezeDelay(0);
    PrintFreezeItems();
    ClearResults();
}
BypassGameSafe();
for(int i=0;i<=6000;i++)
{
    SetSearchRange(C_ALLOC);
    MemorySearch(bm,"131842",&gs,DWORD);
    PMAPS GetResults();
    MemoryWrite(bm,"0",0,DWORD);
    PMAPS GetResults();
    AddFreezeItem_All(bm,"0",DWORD,0);
    StartFreeze(bm);
    SetFreezeDelay(0);
    PrintFreezeItems();
    ClearResults();
}
BypassGameSafe();
for(int i=0;i<=6000;i++)
{
    SetSearchRange(C_ALLOC);
    MemorySearch(bm,"9.21956299e-41",&gs,FLOAT);
    PMAPS GetResults();
    MemoryWrite(bm,"0",0,FLOAT);
    PMAPS GetResults();
    AddFreezeItem_All(bm,"0",FLOAT,0);
    StartFreeze(bm);
    SetFreezeDelay(0);
    PrintFreezeItems();
    ClearResults();
}
BypassGameSafe();
for(int i=0;i<=6000;i++)
{
    SetSearchRange(C_ALLOC);
    MemorySearch(bm,"1.5584387e28",&gs,FLOAT);
    PMAPS GetResults();
    MemoryWrite(bm,"0",0,FLOAT);
    PMAPS GetResults();
    AddFreezeItem_All(bm,"0",FLOAT,0);
    StartFreeze(bm);
    SetFreezeDelay(0);
    PrintFreezeItems();
    ClearResults();
}
BypassGameSafe();
for(int i=0;i<=6000;i++)
{
    SetSearchRange(C_ALLOC);
    MemorySearch(bm,"157567",&gs,DWORD);
    PMAPS GetResults();
    MemoryWrite(bm,"0",0,DWORD);
    PMAPS GetResults();
    AddFreezeItem_All(bm,"0",DWORD,0);
    StartFreeze(bm);
    SetFreezeDelay(0);
    PrintFreezeItems();
    ClearResults();
}
BypassGameSafe();
for(int i=0;i<=6000;i++)
{
    SetSearchRange(C_ALLOC);
    MemorySearch(bm,"133634",&gs,DWORD);
    PMAPS GetResults();
    MemoryWrite(bm,"0",0,DWORD);
    PMAPS GetResults();
    AddFreezeItem_All(bm,"0",DWORD,0);
    StartFreeze(bm);
    SetFreezeDelay(0);
    PrintFreezeItems();
    ClearResults();
}
BypassGameSafe();
for(int i=0;i<=6000;i++)
{
    SetSearchRange(C_ALLOC);
    MemorySearch(bm,"131104",&gs,DWORD);
    PMAPS GetResults();
    MemoryWrite(bm,"0",0,DWORD);
    PMAPS GetResults();
    AddFreezeItem_All(bm,"0",DWORD,0);
    StartFreeze(bm);
    SetFreezeDelay(0);
    PrintFreezeItems();
    ClearResults();
}
BypassGameSafe();
for(int i=0;i<=6000;i++)
{
    SetSearchRange(C_ALLOC);
    MemorySearch(bm,"135426",&gs,DWORD);
    PMAPS GetResults();
    MemoryWrite(bm,"0",0,DWORD);
    PMAPS GetResults();
    AddFreezeItem_All(bm,"0",DWORD,0);
    StartFreeze(bm);
    SetFreezeDelay(0);
    PrintFreezeItems();
    ClearResults();
}
BypassGameSafe();
for(int i=0;i<=6000;i++)
{
    SetSearchRange(C_ALLOC);
    MemorySearch(bm,"135212",&gs,DWORD);
    PMAPS GetResults();
    MemoryWrite(bm,"0",0,DWORD);
    PMAPS GetResults();
    AddFreezeItem_All(bm,"0",DWORD,0);
    StartFreeze(bm);
    SetFreezeDelay(0);
    PrintFreezeItems();
    ClearResults();
}
BypassGameSafe();
for(int i=0;i<=6000;i++)
{
    SetSearchRange(C_ALLOC);
    MemorySearch(bm,"132098",&gs,DWORD);
    PMAPS GetResults();
    MemoryWrite(bm,"0",0,DWORD);
    PMAPS GetResults();
    AddFreezeItem_All(bm,"0",DWORD,0);
    StartFreeze(bm);
    SetFreezeDelay(0);
    PrintFreezeItems();
    ClearResults();
}
BypassGameSafe();
for(int i=0;i<=6000;i++)
{
    SetSearchRange(C_ALLOC);
    MemorySearch(bm,"135938",&gs,DWORD);
    PMAPS GetResults();
    MemoryWrite(bm,"0",0,DWORD);
    PMAPS GetResults();
    AddFreezeItem_All(bm,"0",DWORD,0);
    StartFreeze(bm);
    SetFreezeDelay(0);
    PrintFreezeItems();
    ClearResults();
}
BypassGameSafe();
for(int i=0;i<=6000;i++)
{
    SetSearchRange(C_ALLOC);
    MemorySearch(bm,"132098",&gs,DWORD);
    PMAPS GetResults();
    MemoryWrite(bm,"0",0,DWORD);
    PMAPS GetResults();
    AddFreezeItem_All(bm,"0",DWORD,0);
    StartFreeze(bm);
    SetFreezeDelay(0);
    PrintFreezeItems();
    ClearResults();
}
BypassGameSafe();
for(int i=0;i<=6000;i++)
{
    SetSearchRange(C_ALLOC);
    MemorySearch(bm,"144387",&gs,DWORD);
    PMAPS GetResults();
    MemoryWrite(bm,"0",0,DWORD);
    PMAPS GetResults();
    AddFreezeItem_All(bm,"0",DWORD,0);
    StartFreeze(bm);
    SetFreezeDelay(0);
    PrintFreezeItems();
    ClearResults();
}
BypassGameSafe();
for(int i=0;i<=6000;i++)
{
    SetSearchRange(C_ALLOC);
    MemorySearch(bm,"132354",&gs,DWORD);
    PMAPS GetResults();
    MemoryWrite(bm,"0",0,DWORD);
    PMAPS GetResults();
    AddFreezeItem_All(bm,"0",DWORD,0);
    StartFreeze(bm);
    SetFreezeDelay(0);
    PrintFreezeItems();
    ClearResults();
}
BypassGameSafe();
for(int i=0;i<=6000;i++)
{
    SetSearchRange(C_ALLOC);
    MemorySearch(bm,"132610",&gs,DWORD);
    PMAPS GetResults();
    MemoryWrite(bm,"0",0,DWORD);
    PMAPS GetResults();
    AddFreezeItem_All(bm,"0",DWORD,0);
    StartFreeze(bm);
    SetFreezeDelay(0);
    PrintFreezeItems();
    ClearResults();
}
BypassGameSafe();
for(int i=0;i<=6000;i++)
{
    SetSearchRange(C_ALLOC);
    MemorySearch(bm,"132866",&gs,DWORD);
    PMAPS GetResults();
    MemoryWrite(bm,"0",0,DWORD);
    PMAPS GetResults();
    AddFreezeItem_All(bm,"0",DWORD,0);
    StartFreeze(bm);
    SetFreezeDelay(0);
    PrintFreezeItems();
    ClearResults();
}
BypassGameSafe();
for(int i=0;i<=6000;i++)
{
    SetSearchRange(C_ALLOC);
    MemorySearch(bm,"131586",&gs,DWORD);
    PMAPS GetResults();
    MemoryWrite(bm,"0",0,DWORD);
    PMAPS GetResults();
    AddFreezeItem_All(bm,"0",DWORD,0);
    StartFreeze(bm);
    SetFreezeDelay(0);
    PrintFreezeItems();
    ClearResults();
}
BypassGameSafe();
for(int i=0;i<=6000;i++)
{
    SetSearchRange(C_ALLOC);
    MemorySearch(bm,"134402",&gs,DWORD);
    PMAPS GetResults();
    MemoryWrite(bm,"0",0,DWORD);
    PMAPS GetResults();
    AddFreezeItem_All(bm,"0",DWORD,0);
    StartFreeze(bm);
    SetFreezeDelay(0);
    PrintFreezeItems();
    ClearResults();
}
BypassGameSafe();
for(int i=0;i<=6000;i++)
{
    SetSearchRange(C_ALLOC);
    MemorySearch(bm,"139267",&gs,DWORD);
    PMAPS GetResults();
    MemoryWrite(bm,"0",0,DWORD);
    PMAPS GetResults();
    AddFreezeItem_All(bm,"0",DWORD,0);
    StartFreeze(bm);
    SetFreezeDelay(0);
    PrintFreezeItems();
    ClearResults();
}
BypassGameSafe();
for(int i=0;i<=6000;i++)
{
    SetSearchRange(C_ALLOC);
    MemorySearch(bm,"131072",&gs,DWORD);
    PMAPS GetResults();
    MemoryWrite(bm,"0",0,DWORD);
    PMAPS GetResults();
    AddFreezeItem_All(bm,"0",DWORD,0);
    StartFreeze(bm);
    SetFreezeDelay(0);
    PrintFreezeItems();
    ClearResults();
}
BypassGameSafe();
for(int i=0;i<=6000;i++)
{
    SetSearchRange(C_ALLOC);
    MemorySearch(bm,"134402",&gs,DWORD);
    PMAPS GetResults();
    MemoryWrite(bm,"0",0,DWORD);
    PMAPS GetResults();
    AddFreezeItem_All(bm,"0",DWORD,0);
    StartFreeze(bm);
    SetFreezeDelay(0);
    PrintFreezeItems();
    ClearResults();
}
BypassGameSafe();
for(int i=0;i<=6000;i++)
{
    SetSearchRange(C_ALLOC);
    MemorySearch(bm,"131331",&gs,DWORD);
    PMAPS GetResults();
    MemoryWrite(bm,"0",0,DWORD);
    PMAPS GetResults();
    AddFreezeItem_All(bm,"0",DWORD,0);
    StartFreeze(bm);
    SetFreezeDelay(0);
    PrintFreezeItems();
    ClearResults();
}
BypassGameSafe();
for(int i=0;i<=6000;i++)
{
    SetSearchRange(C_ALLOC);
    MemorySearch(bm,"131586",&gs,DWORD);
    PMAPS GetResults();
    MemoryWrite(bm,"0",0,DWORD);
    PMAPS GetResults();
    AddFreezeItem_All(bm,"0",DWORD,0);
    StartFreeze(bm);
    SetFreezeDelay(0);
    PrintFreezeItems();
    ClearResults();
}
BypassGameSafe();
for(int i=0;i<=6000;i++)
{
    SetSearchRange(C_ALLOC);
    MemorySearch(bm,"134403",&gs,DWORD);
    PMAPS GetResults();
    MemoryWrite(bm,"0",0,DWORD);
    PMAPS GetResults();
    AddFreezeItem_All(bm,"0",DWORD,0);
    StartFreeze(bm);
    SetFreezeDelay(0);
    PrintFreezeItems();
    ClearResults();
}BypassGameSafe();
for(int i=0;i<=6000;i++)
{
    SetSearchRange(C_ALLOC);
    MemorySearch(bm,"134659",&gs,DWORD);
    PMAPS GetResults();
    MemoryWrite(bm,"0",0,DWORD);
    PMAPS GetResults();
    AddFreezeItem_All(bm,"0",DWORD,0);
    StartFreeze(bm);
    SetFreezeDelay(0);
    PrintFreezeItems();
    ClearResults();
}
BypassGameSafe();
for(int i=0;i<=6000;i++)
{
    SetSearchRange(C_ALLOC);
    MemorySearch(bm,"135170",&gs,DWORD);
    PMAPS GetResults();
    MemoryWrite(bm,"0",0,DWORD);
    PMAPS GetResults();
    AddFreezeItem_All(bm,"0",DWORD,0);
    StartFreeze(bm);
    SetFreezeDelay(0);
    PrintFreezeItems();
    ClearResults();
}
BypassGameSafe();
for(int i=0;i<=6000;i++)
{
    SetSearchRange(C_ALLOC);
    MemorySearch(bm,"131588",&gs,DWORD);
    PMAPS GetResults();
    MemoryWrite(bm,"0",0,DWORD);
    PMAPS GetResults();
    AddFreezeItem_All(bm,"0",DWORD,0);
    StartFreeze(bm);
    SetFreezeDelay(0);
    PrintFreezeItems();
    ClearResults();
}
BypassGameSafe();
for(int i=0;i<=6000;i++)
{
    SetSearchRange(C_ALLOC);
    MemorySearch(bm,"147971",&gs,DWORD);
    PMAPS GetResults();
    MemoryWrite(bm,"0",0,DWORD);
    PMAPS GetResults();
    AddFreezeItem_All(bm,"0",DWORD,0);
    StartFreeze(bm);
    SetFreezeDelay(0);
    PrintFreezeItems();
    ClearResults();
}
BypassGameSafe();
for(int i=0;i<=6000;i++)
{
    SetSearchRange(C_ALLOC);
    MemorySearch(bm,"197892",&gs,DWORD);
    PMAPS GetResults();
    MemoryWrite(bm,"0",0,DWORD);
    PMAPS GetResults();
    AddFreezeItem_All(bm,"0",DWORD,0);
    StartFreeze(bm);
    SetFreezeDelay(0);
    PrintFreezeItems();
    ClearResults();
}
puts("BYPASS MADE BY TeamJOYoP");
}