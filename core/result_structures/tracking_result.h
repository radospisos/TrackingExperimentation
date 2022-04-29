//
// Created by Rodion Shyshkin on 28.04.2022.
//

#ifndef EXP4_TRACKING_RESULT_H
#define EXP4_TRACKING_RESULT_H

#include <optional>
#include <opencv2/opencv.hpp>
#include <core/result_structures/correction_controller.h>

namespace fatal_errors {
    static const std::string WRONG_FIELD_ACCESS = "Wrong field access.";
}

class TrackingResult {
public:
    static TrackingResult success(const cv::Rect2d& bb, const CorrectionController& controller);
    static TrackingResult fail();

    bool success() const;
    cv::Rect2d bb() const;
    CorrectionController controller() const;
    double dx() const;
    double dy() const;

private:
    TrackingResult(bool success, const std::optional<cv::Rect2d>& bb, const std::optional<CorrectionController>& controller);

private:
    const bool success_;
    const std::optional<cv::Rect2d> bb_;
    const std::optional<CorrectionController> controller_;
};


#endif //EXP4_TRACKING_RESULT_H
