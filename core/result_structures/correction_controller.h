//
// Created by Rodion Shyshkin on 28.04.2022.
//

#ifndef EXP4_CORRECTION_CONTROLLER_H
#define EXP4_CORRECTION_CONTROLLER_H

#include <string>

namespace fatal_errors {
    static const std::string AMBIGUOUS_CONTROLLER_RESULTS = "Ambiguous Controller result.";
}

class CorrectionController {
public:
    CorrectionController();
    CorrectionController(double dx, double dy);

    double dx() const;
    double dy() const;

private:
    double dx_;
    double dy_;
};


#endif //EXP4_CORRECTION_CONTROLLER_H
