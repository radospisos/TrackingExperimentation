//
// Created by Rodion Shyshkin on 28.04.2022.
//

#ifndef EXP4_KCF_H
#define EXP4_KCF_H

#include <core/tracker.h>

class KCF : public Tracker {
public:
    KCF();

    void init(const cv::Rect2d &init_bb, const cv::Mat &init_frame, int frameW, int frameH) override;
    TrackingResult update(const cv::Mat& frame) override;

private:
    cv::Ptr<cv::TrackerKCF> tracker_;
    cv::Rect2d current_bb_;
    int frame_width_;
    int frame_height_;
};


#endif //EXP4_KCF_H
