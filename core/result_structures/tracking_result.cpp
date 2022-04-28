//
// Created by Rodion Shyshkin on 28.04.2022.
//

#include "tracking_result.h"

TrackingResult::TrackingResult(bool success,
                               const std::optional<cv::Rect2d>& bb,
                               const std::optional<CorrectionController>& controller) :
                               success_(success),
                               bb_(bb),
                               controller_(controller) { }

TrackingResult TrackingResult::success(const cv::Rect2d &bb, const CorrectionController &controller) {
    return TrackingResult{true, bb, controller};
}

TrackingResult TrackingResult::fail() {
    return TrackingResult{false, std::nullopt, std::nullopt};
}

bool TrackingResult::success() const { return success_; }
cv::Rect2d TrackingResult::bb() const {
    if(!success_) throw std::domain_error(fatal_errors::WRONG_FIELD_ACCESS);
    return bb_.value();
}
CorrectionController TrackingResult::controller() const {
    if(!success_) throw std::domain_error(fatal_errors::WRONG_FIELD_ACCESS);
    return controller_.value();
}
bool TrackingResult::up() const {
    if(!controller_.has_value()) throw std::domain_error(fatal_errors::WRONG_FIELD_ACCESS);
    return controller_.value().up();
}
bool TrackingResult::down() const {
    if(!controller_.has_value()) throw std::domain_error(fatal_errors::WRONG_FIELD_ACCESS);
    return controller_.value().down();
}
bool TrackingResult::left() const {
    if(!controller_.has_value()) throw std::domain_error(fatal_errors::WRONG_FIELD_ACCESS);
    return controller_.value().left();
}
bool TrackingResult::right() const {
    if(!controller_.has_value()) throw std::domain_error(fatal_errors::WRONG_FIELD_ACCESS);
    return controller_.value().right();
}