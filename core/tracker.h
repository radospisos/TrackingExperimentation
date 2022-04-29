//
// Created by Rodion Shyshkin on 28.04.2022.
//

#ifndef EXP4_TRACKER_H
#define EXP4_TRACKER_H

#include <opencv2/tracking/tracking.hpp>
#include <core/result_structures/tracking_result.h>
#include <core/trackers/core_utils/core_utils.h>

class Tracker {
public:
    virtual ~Tracker() = default;

    virtual void init(const cv::Rect2d &init_bb, const cv::Mat &init_frame) = 0;
    virtual TrackingResult update(const cv::Mat& frame) = 0;
};

#endif //EXP4_TRACKER_H
