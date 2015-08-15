#include <iostream>
#include <cstdlib>
#include <fstream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>


int main(int argc, char* argv[])
{
    cv::Mat A(600, 800, CV_8UC1);
    cv::Mat B(600, 800, CV_8UC3);

    for(int h = 0; h < A.rows; ++h){
        uchar *p = A.ptr<uchar>(h);
        for (int w = 0; w < A.cols; ++w){
            //A.at<uchar>(h, w) = (h + w) % 255;
            //A.at<uchar>(h, w) = rand();
            p[w] = (h+w) % 255;
        }
    }
    for(int h = 0; h < B.rows; ++h){
        cv::Vec3b *p = B.ptr<cv::Vec3b>(h);
        for(int w = 0; w < B.cols; ++w){
//            for(int c = 0; c < B.channels(); ++c){
//                cv::Vec3b pixel;
//                pixel[0] = h % 255;
//                pixel[1] = w % 255;
//                pixel[2] = 0;
//                B.at<cv::Vec3b>(h, w) = pixel;
//            }
            p[w][0] = h % 255;
            p[w][1] = w % 255;
            p[w][2] = 0;
        }
    }
    std::cout << B(cv::Range::all(), cv::Range(1, 2)) << std::endl;
    std::cout << B(cv::Rect(10, 10, 100, 100)) << std::endl;
    cv::imshow("gray image", A);
    cv::imshow("color image", B);
    cv::waitKey(0);

    int a = 0;
    return a;
}
