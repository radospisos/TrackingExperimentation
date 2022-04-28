//
// Created by Rodion Shyshkin on 28.04.2022.
//

#include "medianflow.h"

MedianFlow::MedianFlow() {
    tracker_ = cv::TrackerMedianFlow::create();
}

void MedianFlow::init(const cv::Rect2d &init_bb, const cv::Mat &init_frame, int frameW, int frameH) {
    this->frame_width_ = frameW;
    this->frame_height_ = frameH;

    tracker_->init(init_frame, init_bb);
    current_bb_ = init_bb;
}

TrackingResult MedianFlow::update(const cv::Mat &frame) {
    bool success = tracker_->update(frame, current_bb_);

    if(success) {
        cv::Mat current_frame = frame;
        cv::rectangle(current_frame, current_bb_, cv::Scalar(0, 255, 0), 1, cv::LINE_8, 0);

        auto controller = core_utils::get_controller(current_bb_, frame_width_, frame_height_);
        return TrackingResult::success(current_bb_, controller);
    }
    else {
        return TrackingResult::fail();
    }
}