fname = get_string("Enter the filename:",'');
global.fileid = file_text_open_write(fname);
file_text_write_string(global.fileid,string(hblocks) + " " + string(vblocks));
file_text_writeln(global.fileid);

for (i = 0; i < vblocks; i += 1)
{
    for (j = 0; j < hblocks; j += 1)
    {
        file_text_write_string(global.fileid,string(blocks[j,i]) + " ");
    }
    file_text_writeln(global.fileid);
}
