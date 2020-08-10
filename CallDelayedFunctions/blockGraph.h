GMEXPORT double blockGraph_create3DModel(double double_blockGraph);
GMEXPORT double blockGraph_createSubmodel(double double_blockGraph, double modelID);
GMEXPORT double blockGraph_blockArithmetic(double double_blockGraph, double blockID);
GMEXPORT double blockGraph_setUpBlockGraphList(double double_blockGraph);
GMEXPORT double blockGraph_addToBlockUpdateList(double double_blockGraph, double blockID);
GMEXPORT double blockGraph_updateBlockGraphWithList(double double_blockGraph);
GMEXPORT double blockGraph_addToTempBlockUpdateList(double double_blockGraph, double blockID);
GMEXPORT double blockGraph_getSideWithPoint(double double_blockGraph, double blockID, double x, double y, double z);
GMEXPORT double blockGraph_loadFromFile(char* fileName);
