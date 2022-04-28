//
// Created by Rodion Shyshkin on 28.04.2022.
//

#include "correction_controller.h"

CorrectionController CorrectionController::create(bool up, bool down, bool left, bool right) {
    if((up && down) || (left && right)) throw std::invalid_argument(fatal_errors::AMBIGUOUS_CONTROLLER_RESULTS);
    return CorrectionController{up, down, left, right};
}

CorrectionController::CorrectionController(bool up, bool down, bool left, bool right) {
    up_ = up;
    down_ = down;
    left_ = left;
    right_ = right;
}

bool CorrectionController::up() const { return up_; }
bool CorrectionController::down() const { return down_; }
bool CorrectionController::left() const { return left_; }
bool CorrectionController::right() const { return right_; }