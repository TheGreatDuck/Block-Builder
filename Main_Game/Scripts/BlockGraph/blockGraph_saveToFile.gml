file = file_text_open_write(argument[0]);

file_text_write_real(file,numberOfBlockModels);
file_text_writeln(file);

var i;

for (i = 0; i < numberOfBlockModels; i += 1)
{
    file_text_write_real(file,blockGraph[i,Block3D_v1x]);
    file_text_write_real(file,blockGraph[i,Block3D_v1y]);
    file_text_write_real(file,blockGraph[i,Block3D_v1z]);
    file_text_write_real(file,blockGraph[i,Block3D_v2x]);
    file_text_write_real(file,blockGraph[i,Block3D_v2y]);
    file_text_write_real(file,blockGraph[i,Block3D_v2z]);
    file_text_write_real(file,blockGraph[i,Block3D_v3x]);
    file_text_write_real(file,blockGraph[i,Block3D_v3y]);
    file_text_write_real(file,blockGraph[i,Block3D_v3z]);
    file_text_write_real(file,blockGraph[i,Block3D_v4x]);
    file_text_write_real(file,blockGraph[i,Block3D_v4y]);
    file_text_write_real(file,blockGraph[i,Block3D_v4z]);
    file_text_write_real(file,blockGraph[i,Block3D_adj1]);
    file_text_write_real(file,blockGraph[i,Block3D_adj2]);
    file_text_write_real(file,blockGraph[i,Block3D_adj3]);
    file_text_write_real(file,blockGraph[i,Block3D_adj4]);
    file_text_write_real(file,blockGraph[i,Block3D_type]);
    file_text_write_real(file,blockGraph[i,Block3D_removable]);
    file_text_write_real(file,blockGraph[i,Block3D_n1x]);
    file_text_write_real(file,blockGraph[i,Block3D_n1y]);
    file_text_write_real(file,blockGraph[i,Block3D_n1z]);
    file_text_write_real(file,blockGraph[i,Block3D_n2x]);
    file_text_write_real(file,blockGraph[i,Block3D_n2y]);
    file_text_write_real(file,blockGraph[i,Block3D_n2z]);
    file_text_write_real(file,blockGraph[i,Block3D_n3x]);
    file_text_write_real(file,blockGraph[i,Block3D_n3y]);
    file_text_write_real(file,blockGraph[i,Block3D_n3z]);
    file_text_write_real(file,blockGraph[i,Block3D_n4x]);
    file_text_write_real(file,blockGraph[i,Block3D_n4y]);
    file_text_write_real(file,blockGraph[i,Block3D_n4z]);
    file_text_writeln(file);
}
