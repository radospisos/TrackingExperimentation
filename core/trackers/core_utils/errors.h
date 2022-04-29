//
// Created by Rodion Shyshkin on 29.04.2022.
//

#ifndef EXP4_ERRORS_H
#define EXP4_ERRORS_H

#include <string>

namespace fatal_errors {
    static const std::string BB_FRAME_SIZE_ERR = "Sizes of bounding box and frame are ambiguous.";
    static const std::string FRAME_FRAME_SIZE_ERR = "Sizes of current frame and initial frame are ambiguous.";
}

#endif //EXP4_ERRORS_H
