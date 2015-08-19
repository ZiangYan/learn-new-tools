#include <iostream>
#include <cstdlib>
#include <fstream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

void changeMat(cv::Mat M)
{
    uchar *p = M.ptr<uchar>(0);
    p[0] = 23;
}

int main(int argc, char* argv[])
{
    cv::Mat A = cv::imread("../lena.jpg");
    cv::Mat B = A(cv::Range::all(), cv::Range(0, 10));
    std::cout << A(cv::Range(0, 5), cv::Range(0, 5)) << std::endl;
    std::cout << B(cv::Range(0, 5), cv::Range(0, 5)) << std::endl;
    printf("A.data: %p\n", A.data);
    printf("B.data: %p\n", B.data);
    for (int i = 0; i < 50; ++i){
        uchar *p = A.ptr<uchar>(i);
        for (int j = 0; j < 10; ++j){
            p[j] = 0;
        }
    }

    std::cout << A(cv::Range(0, 5), cv::Range(0, 5)) << std::endl;
    std::cout << B(cv::Range(0, 5), cv::Range(0, 5)) << std::endl;
    printf("A.data: %p\n", A.data);
    printf("B.data: %p\n", B.data);
    A = cv::imread("../lena.jpg");
    printf("A.data: %p\n", A.data);
    printf("B.data: %p\n", B.data);
    return 0;
}
