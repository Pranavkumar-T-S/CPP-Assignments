#include "opencv/include/opencv_handler.hpp"
#include "protobuf/include/protobuf_handler.hpp"

int main()
{
    int flag;
    std::cout << "Enter the option\n0 - to use configuration in protobuf\n1 - to get config from console" << std::endl;
    std::cin >> flag;
    OpencvHandler::ImageHandler img = OpencvHandler::ImageHandler();
    ProtobufHandler proto = ProtobufHandler();
    if (flag)
    {
        proto.user_prompt_values();
    }
    struct maskdata mask_config = proto.get_mask_data();
    std::cout << mask_config.cs << ' ' << mask_config.xmin << ' ' << mask_config.xmax << ' ' << mask_config.ymin << ' ' << mask_config.ymax << ' ' << mask_config.zmin << ' ' << mask_config.zmax << std::endl;
    img.imshow();
    if (mask_config.cs == imgmask::HSV)
    {
        img.BGRtoHSV();
        img.imshow();
    }
    img.mask_by_range(mask_config.xmin, mask_config.xmax, mask_config.ymin, mask_config.ymax, mask_config.zmin, mask_config.zmax);
    img.imshow();
    if (mask_config.cs == imgmask::HSV)
    {
        img.HSVtoBGR();
        img.imshow();
    }

    return 0;
}