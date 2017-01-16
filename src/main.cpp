#include "opencv2/core/version.hpp"
#include <opencv2/core/core.hpp>
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/opencv.hpp>
#include <iostream>
#include <omp.h>

using namespace cv;
using namespace std;

void readDetectAndPrint(string imageName, CascadeClassifier model)
{
    Mat img = cv::imread(imageName);
    vector<double> weights;
    vector<int> levels;
    vector<Rect> detections;
    model.detectMultiScale(img, detections, levels, weights, 1.1, 3, 0, Size(), Size(), true);
    if (detections.size() > 0)
    {
        cout << "Detection " << imageName << " " << detections[0] << " with weight " << weights[0] << " and level: " << levels[0] << " and size: " << detections.size() << endl;
    }
}

int main(int argc, char *argv[])
{
    cv::CascadeClassifier model("/home/sam/libs/opencv-3.2.0-without-cuda/data/haarcascades/haarcascade_frontalface_alt.xml");
    readDetectAndPrint("./cropped_face1.png", model);
    readDetectAndPrint("./cropped_face2.png", model);
    readDetectAndPrint("./cropped_face3.png", model);
    readDetectAndPrint("./cropped_face4.png", model);
    readDetectAndPrint("./cropped_face5.png", model);
    readDetectAndPrint("./cropped_face6.png", model);
}
