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
        double dx = 0, dy = 0;

        double fr_center_x = frameW / 2;
        double fr_center_y = frameH / 2;
        double bb_center_x = x + (w / 2);
        double bb_center_y = y + (h / 2);

        dx = bb_center_x - fr_center_x;
        dy = bb_center_y - fr_center_y;

        return CorrectionController{dx, dy};
    }
}

#endif //EXP4_CORE_UTILS_H
