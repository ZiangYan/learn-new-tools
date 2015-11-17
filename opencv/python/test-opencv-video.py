#!/usr/bin/env python
import cv2


# This script indicates a bug in OpenCV 2.4.8 VideoCapture module.
# Use this module to process some video may leads to 'segment fault' error.
# This bug has been successfully fixed in OpenCV 2.4.10 and later version.
# However, install OpenCV in Ubuntu 14.xx using apt-get will install 2.4.8 by default,
# and in Ubuntu 15.xx, apt-get will install 2.4.10 by defualt.
# So, if you want to extract images from video in Ubuntu 14.xx, there are 3 ways:
#   1. upgrade to Ubuntu 15.xx and install OpenCV using apt-get
#   2. build OpenCV 2.4.10 or later from source
#   3. use ffmpeg instead


def main():
    video_name = '/home/yanziang/roadSign2015/data/offical_data/preliminary/videos/001.avi'
    video = cv2.VideoCapture(video_name)
    count = 0
    success, frame = video.read()
    while success:
        cv2.imwrite('./%d.jpg' % count, frame)
        count += 1
        success, frame = video.read()

if __name__ == '__main__':
    main()
