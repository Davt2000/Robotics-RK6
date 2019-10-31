//
// Created by perturabo on 30.10.2019.
//
#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/video.hpp>
#include <opencv2/imgcodecs.hpp>



using namespace cv;

int main(int, char**) {
    VideoCapture cap(0); // open the default camera
    cap.set(cv::CAP_PROP_FOURCC, cv::VideoWriter::fourcc ('H', '2', '6', '4'));
    cap.set (CAP_PROP_POS_FRAMES, 3);

    if(!cap.isOpened())  // check if we succeeded
      return -1;

    Mat edges;
    Mat frame;
    namedWindow("edges",1);

    for(;;){
        clock_t a = clock();

        bool bSuccess = cap.read(frame);

        if(!bSuccess){
            std::cout << "Cannot read a frame from video stream" << std::endl;
            break;
        }

        cvtColor(frame, edges, COLOR_BGR2GRAY);

        GaussianBlur(edges, edges, Size(7,7), 1.5, 1.5);
        Canny(edges, edges, 0, 30, 3);

        imshow("edges", edges);

        if(waitKey(30) >= 0) break;
    }

    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}