fillerModel = d3d_model_create();
numberOfModels = ceil(numberOfBlockModels/blockModelCapacity);
for (i = 0; i < numberOfModels; i+=1)
{
    surfaceModel[i] = blockGraph_createSubmodel(i);
}
