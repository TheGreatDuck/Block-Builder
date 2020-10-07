typedef struct linkedNode
{
    void*  data;
    struct linkedNode* next;
    struct linkedNode* previous;
} linkedNode;

typedef struct linkedCycle
{
    linkedNode* current;
    int         length;
} linkedCycle;

linkedCycle* createCycle();
void insertAfterCurrent(linkedCycle* cycle, double data);
void removeAfterCurrent(linkedCycle* cycle);
int getLength(linkedCycle* cycle);
void* getCurrentData(linkedCycle* cycle);
void next(linkedCycle* cycle);
void previous(linkedCycle* cycle);
linkedNode* getCurrentNode(linkedCycle* cycle);
void setCurrentNode(linkedCycle* cycle, linkedNode* node);
void setLength(linkedCycle* cycle, int length);
