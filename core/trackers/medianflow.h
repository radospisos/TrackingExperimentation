//
// Created by Rodion Shyshkin on 28.04.2022.
//

#ifndef EXP4_MEDIANFLOW_H
#define EXP4_MEDIANFLOW_H


//
// Created by Rodion Shyshkin on 28.04.2022.
//

#include <core/tracker.h>

class MedianFlow : public Tracker
{
    public:
    MedianFlow();

    void init(const cv::Rect2d &init_bb, const cv::Mat &init_frame, int frameW, int frameH) override;
    TrackingResult update(const cv::Mat& frame) override;

    private:
    cv::Ptr<cv::TrackerMedianFlow> tracker_;
    cv::Rect2d current_bb_;
    int frame_width_;
    int frame_height_;
};

#endif //EXP4_MEDIANFLOW_H
