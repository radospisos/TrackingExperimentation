//
// Created by Rodion Shyshkin on 28.04.2022.
//

#include "correction_controller.h"

CorrectionController::CorrectionController() {
    dx_ = 0.0;
    dy_ = 0.0;
}

CorrectionController::CorrectionController(double dx, double dy) {
    dx_ = dx;
    dy_ = dy;
}

double CorrectionController::dx() const { return dx_; }
double CorrectionController::dy() const { return dy_; }