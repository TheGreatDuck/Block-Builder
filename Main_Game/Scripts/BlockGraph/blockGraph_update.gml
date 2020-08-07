with (obj_blockGraph)
{
    var i;
    for (i = 0; i < numberOfBlockModels; i += 1)
    {
        tempBlocks[i] = blockGraph_blockArithmetic(i);
    }
    
    var changed;
    changed = 0;
    for (i = 0; i < numberOfBlockModels; i += 1)
    {
        if (blockGraph[i,Block3D_type] != tempBlocks[i])
        {
            
            blockGraph[i,Block3D_type] = tempBlocks[i];
            changed = 1;
            /*show_message("it executed");
            d3d_set_projection_ortho(0,0, power(2,ceil(log2(numberOfBlockModels)))*64, 64, 0);
            surface_set_target(blockGraphSurface);
            draw_sprite(spr_tileSet,square_getBlockType(blockGraph[i]),64*i,0);
            surface_reset_target();*/
        }
    }
    
    if (changed == 1)
    {
        d3d_model_destroy(surfaceModel);
        surfaceModel = blockGraph_create3DModel();
    }
}
