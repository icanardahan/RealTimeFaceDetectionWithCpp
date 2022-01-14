#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
    VideoCapture cap(0);
    Mat img;

    while (true){

        cap.read(img);
    

    CascadeClassifier face_cascade;
    face_cascade.load("haarcascade_frontalface_default.xml");

    if(face_cascade.empty())
    {
        cout << "Error loading face cascade" << endl;
        return -1;
    }

    vector<Rect> faces;
    face_cascade.detectMultiScale(img, faces, 1.1, 10);


    for(int i = 0; i < faces.size(); i++)
    {
        rectangle(img, faces[i], Scalar(255, 0, 0), 2);
    }

   imshow("Image",img);
   waitKey(1); 

}


}
