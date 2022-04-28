//
// Created by Rodion Shyshkin on 28.04.2022.
//

#ifndef EXP4_CORRECTION_CONTROLLER_H
#define EXP4_CORRECTION_CONTROLLER_H

#include <string>
#include <stdexcept>

namespace fatal_errors {
    static const std::string AMBIGUOUS_CONTROLLER_RESULTS = "Controller result is ambiguous.";
}

class CorrectionController {
public:
    static CorrectionController create(bool up, bool down, bool left, bool right);

    bool up() const;
    bool down() const;
    bool left() const;
    bool right() const;

private:
    CorrectionController(bool up, bool down, bool left, bool right);

private:
    bool up_;
    bool down_;
    bool left_;
    bool right_;
};


#endif //EXP4_CORRECTION_CONTROLLER_H
