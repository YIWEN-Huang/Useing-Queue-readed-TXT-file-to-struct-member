# Useing-Queue-readed-TXT-file-to-struct-member
The read file code, using Queue concept to read file and get byte by byte, then will check the Character will going to what struct need, for example
In 123.txt file frist Character is title, step: 
1. Frist reading file into buffer.
2. move buffer to Queue, get one byte, and analyze character by byte.
3. the program check from blank(' ') to separation.
4. move the character befer blank to buffer1.
5. move to struct-> title. 
6. Done.
