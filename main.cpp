#include "utils/constants.h"
#include "utils/tracker_creator.h"

int main()
{
    try {
        // Reading the first frame.
        cv::Mat init_frame;
        cv::VideoCapture cap(constants::VIDEOPATH);
        cap >> init_frame;
        if(init_frame.empty()) std::cout << constants::EMPTY_FRAME_ERROR << std::endl;

        cv::Rect2d roi = cv::selectROI(init_frame, false, false);

        // Creating initBB and initializing of the tracker.
        std::unique_ptr<Tracker> tracker = tracker_creator::create(constants::TRACKER_NAME);
        tracker->init(roi, init_frame, roi.width, roi.height);


        // Loop through all frames with object tracking.
        while(cap.isOpened()) {
            // Reading the next frame and tracking the object.
            cv::Mat frame;
            cap >> frame;
            if (frame.empty()) break;

            auto result = tracker->update(frame);
            if (result.success()) {
                std::cout << "Up: " << result.up() << ". Down: " << result.down() << ". Left: " << result.left()
                          << ". Right: " << result.right() << std::endl;
            } else {
                std::cout << "Object was lost" << std::endl;
            }

            // Vizualization.
            cv::imshow("win", frame);
            int key = cv::waitKey(1);
            if(key == 27) { cv::destroyAllWindows(); break; }
        }

    } catch(...) {
        std::cout << constants::WRONG_FILEPATH_ERROR << std::endl;
    }
    return 0;
}
