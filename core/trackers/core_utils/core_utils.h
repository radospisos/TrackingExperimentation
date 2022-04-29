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
        double dx = 0, dy = 0;

        double horizontal_left_point = (frameW - w) / 2;
        double vertical_top_point = (frameH - h) / 2;

        if (x < horizontal_left_point) dx = -(horizontal_left_point - x);
        if (x > horizontal_left_point) dx = (x - horizontal_left_point);
        if (y < vertical_top_point) dy = -(vertical_top_point - y);
        if (y > vertical_top_point) dy = (y - vertical_top_point);

        return CorrectionController{dx, dy};
    }
}

#endif //EXP4_CORE_UTILS_H
