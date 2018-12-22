This is my third C project. The goal is to create get_next_line function (int get_next_line(const int fd, char **line)) wich can consists with not more
5 functions with not more 25 line of each. It's possible to use my c library but without adding new functions for get_next_line. 
I made this projects without lists but with static arrays. Idea was to use this array seems like hash-table with file descriptors as indexes.

For using this function you should call it with file descriptor and buffer for line. Function returns 1 if succes, -1 if failed and 0 if finished reading.
