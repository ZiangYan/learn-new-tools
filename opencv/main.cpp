#include <iostream>
#include <cstdlib>
#include <fstream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

void changeMat(cv::Mat M)
{
    uchar *p = M.ptr<uchar>(0);
    p[0] = 23;
}

int main(int argc, char* argv[])
{
    cv::Mat A(5, 5, CV_8UC1);
    cv::Mat B(5, 5, CV_8UC3);

    for(int h = 0; h < A.rows; ++h){
        uchar *p = A.ptr<uchar>(h);
        for (int w = 0; w < A.cols; ++w){
            //A.at<uchar>(h, w) = (h + w) % 255;
            //A.at<uchar>(h, w) = rand();
            p[w] = (h+w) % 255;
        }
    }
    cv::Mat C = A(cv::Range::all(), cv::Range(1, 3));
    for(int h = 0; h < C.rows; ++h){
        uchar *p = C.ptr<uchar>(h);
        for(int w = 0; w < C.cols; ++w){
            p[w] = 100;
        }
    }
    uchar *pp = C.data;
    pp[0] = 111;
    pp[1] = 111;
    pp[2] = 111;
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
    changeMat(A);
    cv::Mat lut(1, 256, CV_8U);
    uchar *p = lut.data;
    for(int i = 0; i < 256; ++i){
        if(i != 4) 
            p[i] = i;
        else
            p[i] = 45;
    }
    cv::Mat D;
    cv::LUT(A, lut, D);
    std::cout << A << std::endl;
    std::cout << C << std::endl;
    std::cout << D << std::endl;
    //cv::imshow("gray image", A);
    //cv::imshow("color image", B);
    //cv::waitKey(0);

    return 0;
}
