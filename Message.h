#ifndef MESSAGE_H
#define MESSAGE_H
#include "Global_values.h"
#include <vector>
struct Message{
    MessageType type;
    int src;
    int dest;
    int qos;
    union{
        struct {
            int adress;
            int num_of_cache_lines;
            int start_cache_lines;

        }write_me;
        struct {
            int address;
            int size;
        } read_mem;
        struct{
            int cache_line;
        }broadcast_invalidate;
        
        struct{
            std::vector<int> data;
        }read_resp;
        struct {
            int status;

        }write_resp;
        

    }messageDATA;


};


#endif