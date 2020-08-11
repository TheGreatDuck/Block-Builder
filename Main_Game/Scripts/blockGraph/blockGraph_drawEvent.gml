for (i = 0; i  < ceil(numberOfBlockModels/blockModelCapacity); i+=1)
{
    d3d_model_draw(surfaceModel[i],0,0,0,sprite_get_texture(spr_blockTexture,0));
}
