get_next_line (GNL) is a project of making a function what can read from a file descriptor,
then returns a pointer to the allocated memory, where the necessary string is.
get_next_line_bonus can read from different descriptors.

This version of GNL is only for file descriptors from 0 to 255,
  if you want to change this value you need to change MAX_BUFFER in get_next_line.h or get_next_line_bonus.h
    or you can compile it with "-D MAX_BUFFER=your_value" flag
    
This version of GNL uses buffer of 42 bytes,
  if you want to change this value you need to change BUFFER_SIZE in get_next_line.h or get_next_line_bonus.h
    or you can compile it with "-D BUFFER_SIZE=your_value" flag

If something went wrong a GNL will return 0 value.
