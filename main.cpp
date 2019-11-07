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
    // cap.set (CAP_PROP_POS_FRAMES, 3);

    if(!cap.isOpened())  // check if we succeeded
      return -1;

    Mat edges;
    Mat prev;
    Mat improved_edges;
    Mat frame;
    Mat sobel_x_canny;
    Mat contourOutput;
    std::vector<std::vector<cv::Point> > contours;

    namedWindow("edges",1);
    namedWindow("improved_edges",1);
    cap.read(edges);

    for(;;){
        clock_t a = clock();

        bool bSuccess = cap.read(frame);

        if(!bSuccess){
            std::cout << "Cannot read a frame from video stream" << std::endl;
            break;
        }
        contourOutput = frame.clone();
        //contourOutput.convertTo(contourOutput, CV_8UC1);
        cvtColor(frame, edges, COLOR_BGR2GRAY);
        cvtColor(contourOutput, improved_edges, COLOR_BGR2GRAY);
        prev = edges.clone ();

        //GaussianBlur(edges, edges, Size(7,7), 1.5, 1.5);
        //Canny(edges, edges, 0, 30, 3);
        // improved_edges = edges - prev;
        cv::dilate (improved_edges, improved_edges,
            cv::getStructuringElement(
                cv::MORPH_RECT, cv::Size(1,1)
                )
            );
        GaussianBlur(improved_edges, improved_edges, Size(7,7), 1.5, 1.5);
        Canny(improved_edges, improved_edges, 0, 55, 3);
        Sobel(prev, prev, -1, 1, 1);
        sobel_x_canny = prev.clone ();
        Canny (sobel_x_canny, sobel_x_canny, 1, 85, 3);
        imshow("edges", edges);
        imshow("improved_edges", improved_edges);
        imshow("I_am_uporot", prev);
        imshow("Me_too", sobel_x_canny);
        /* cv::findContours(contourOutput, contours, cv::RETR_TREE, cv::CHAIN_APPROX_NONE ); // it drops here

        Mat contourImage(contourOutput.size(), CV_8UC1, cv::Scalar(0,0,0));

        cv::Scalar colors[3];
        colors[0] = cv::Scalar(255, 0, 0);
        colors[1] = cv::Scalar(0, 255, 0);
        colors[2] = cv::Scalar(0, 0, 255);
        for (size_t idx = 0; idx < contours.size(); idx++) {
            cv::drawContours(contourImage, contours, idx, colors[idx % 3]);
          }

        cv::imshow("Contours", contourImage);
        cv::moveWindow("Contours", 200, 0); */

        if(waitKey(30) >= 0) break;
    }

    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}