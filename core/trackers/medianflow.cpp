//
// Created by Rodion Shyshkin on 28.04.2022.
//

#include "medianflow.h"

MedianFlow::MedianFlow() {
    tracker_ = cv::TrackerMedianFlow::create();
}

void MedianFlow::init(const cv::Rect2d &init_bb, const cv::Mat &init_frame) {
    frame_width_ = init_frame.size().width;
    frame_height_ = init_frame.size().height;
    if(init_bb.width > frame_width_ || init_bb.height > frame_height_) throw std::invalid_argument(fatal_errors::BB_FRAME_SIZE_ERR);

    tracker_->init(init_frame, init_bb);
    current_bb_ = init_bb;
}

TrackingResult MedianFlow::update(const cv::Mat &frame) {
    bool success = tracker_->update(frame, current_bb_);
    if(frame.size().width != frame_width_ || frame.size().height != frame_height_) throw std::invalid_argument(fatal_errors::FRAME_FRAME_SIZE_ERR);

    if(success) {
        auto controller = core_utils::get_controller(current_bb_, frame_width_, frame_height_);
        return TrackingResult::success(current_bb_, controller);
    }
    else {
        return TrackingResult::fail();
    }
}