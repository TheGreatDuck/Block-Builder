fname = get_string("Enter the filename:",'');
global.fileid = file_text_open_write(fname);

var i;

for (i = 0; i < TAIL_NODE + 100; i+=1)
{
    file_text_write_string(global.fileid,"HEAP_SPACE[" + string(i) + "] = " + string(HEAP_SPACE[i]) + ";");
		  file_text_writeln(global.fileid);
}
file_text_write_string(global.fileid,"HEAD_NODE = " + string(HEAD_NODE) + ";");
file_text_writeln(global.fileid);
file_text_write_string(global.fileid,"TAIL_NODE = " + string(TAIL_NODE) + ";");
file_text_writeln(global.fileid);
file_text_write_string(global.fileid,"LINKED_LIST_LENGTH = " + string(LINKED_LIST_LENGTH) + ";");
file_text_writeln(global.fileid);
