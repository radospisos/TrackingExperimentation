//
// Created by Rodion Shyshkin on 28.04.2022.
//

#ifndef EXP4_KCF_H
#define EXP4_KCF_H

#include <core/tracker.h>

namespace fatal_errors {
    static const std::string BB_FRAME_SIZE_ERR = "Sizes of bounding box and frame are ambiguous.";
    static const std::string FRAME_FRAME_SIZE_ERR = "Sizes of current frame and initial frame are ambiguous.";
}

class KCF : public Tracker {
public:
    KCF();

    void init(const cv::Rect2d &init_bb, const cv::Mat &init_frame) override;
    TrackingResult update(const cv::Mat& frame) override;

private:
    cv::Ptr<cv::TrackerKCF> tracker_;
    cv::Rect2d current_bb_;
    int frame_width_;
    int frame_height_;
};


#endif //EXP4_KCF_H
