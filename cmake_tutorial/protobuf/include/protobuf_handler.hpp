#include <fstream>
#include <iostream>
#include "imgmask.pb.h"
#ifndef __PROTOFILE__
#define __PROTOFILE__ "configuration.protobuf"
#endif
extern std::string x_param[2], y_param[2], z_param[2];

struct maskdata
{
    imgmask::colorspace cs;
    int xmin, xmax, ymin, ymax, zmin, zmax;
};

class ProtobufHandler
{
    imgmask::maskdetails mask1;
    std::string filename;
    bool load();
    bool dump();

public:
    ProtobufHandler(std::string = __PROTOFILE__);
    ~ProtobufHandler();
    void set_default_values();
    void user_prompt_values();
    maskdata get_mask_data();
};