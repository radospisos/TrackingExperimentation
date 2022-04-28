//
// Created by Rodion Shyshkin on 28.04.2022.
//

#ifndef EXP4_CORE_UTILS_H
#define EXP4_CORE_UTILS_H

#include <opencv2/opencv.hpp>
#include <core/result_structures/correction_controller.h>

namespace core_utils {
    static CorrectionController get_controller(const cv::Rect2d& bb, const double& frameW, const double& frameH) {
        double x = bb.x, y = bb.y, w = bb.width, h = bb.height;
        bool up = false, down = false, left = false, right = false;

        double horizontal_left_point = (frameW - w) / 2;
        double vertical_top_point = (frameH - h) / 2;

        if (x < horizontal_left_point) left = true;
        if (x > (horizontal_left_point + w)) right = true;
        if (y < vertical_top_point) up = true;
        if (y > (vertical_top_point + h)) down = true;

        return CorrectionController::create(up, down, left, right);
    }
}

#endif //EXP4_CORE_UTILS_H
