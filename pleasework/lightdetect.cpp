using namespace cv;

cv::Mat lightfilter(Mat mat){
    Mat output, gray, smoothed, threshed, eroded, dilated;
    cv::cvtColor(mat, gray, COLOR_BGR22GRAY);
    cv::GaussianBlur(gray, smoothed, Size(11,11), 0, 0);
    double thresh = 200.0;
    double maxval = 255.0;
    cv::threshold(smoothed,threshed,thresh,maxval,THRESH_BINARY);
    int erosion_size=0;
    int dilation_size=0;
    cv::Mat kernel=getStructuringElement(MORPH_RECT,Size(2*erosion_size+1, 2*erosion_size+1),Point(erosion_size, erosion_size));
    cv::erode(threshed,eroded,kernel);
    cv::Mat kernel2=getStructuringElement(MORPH_RECT,Size(2*dilation_size+1, 2*dilation_size+1),Point(dilation_size, dilation_size));
    cv::dilate(eroded,dilated,kernel2);


}
