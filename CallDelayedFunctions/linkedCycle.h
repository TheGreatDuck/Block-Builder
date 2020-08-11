typedef struct linkedNode
{
    double      data;
    struct linkedNode* next;
    struct linkedNode* previous;
    double      dataDestructor;
} linkedNode;

typedef struct linkedCycle
{
    linkedNode* current;
    double      dataDestructor;
    int         length;
} linkedCycle;

linkedCycle* createCycle(double dataDestructor);
void insertAfterCurrent(linkedCycle* cycle, double data);
void removeAfterCurrent(linkedCycle* cycle);
int getLength(linkedCycle* cycle);
double getCurrentData(linkedCycle* cycle);
double next(linkedCycle* cycle);
linkedNode* getCurrentNode(linkedCycle* cycle);
void setCurrentNode(linkedCycle* cycle, linkedNode* node);
void setLength(linkedCycle* cycle, int length);
