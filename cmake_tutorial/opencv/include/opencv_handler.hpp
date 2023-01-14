#include <opencv2/photo.hpp>
#ifndef __INPUT__
#define __INPUT__ "input.jpeg"
#endif
#ifndef __OUTPUT__
#define __OUTPUT__ "output.jpeg"
#endif
namespace OpencvHandler
{
    enum ColorSpaces
    {
        BGR,
        HSV
    };

    class ImageHandler
    {
        cv::Mat image;
        std::string inputfile;
        std::string outputfile;
        ColorSpaces colorspace;
        void imread();
        void imwrite();

    public:
        ImageHandler(std::string = __INPUT__, std::string = __OUTPUT__);
        ~ImageHandler();
        void imshow();
        void BGRtoHSV();
        void HSVtoBGR();
        void mask_by_range(int, int, int, int, int, int);
    };

}