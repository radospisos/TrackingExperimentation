//
// Created by Rodion Shyshkin on 28.04.2022.
//

#ifndef EXP4_CONSTANTS_H
#define EXP4_CONSTANTS_H

#include <string>
#include <optional>
#include <utils/tracker_type.h>

namespace constants {
    static const std::string VIDEOPATH = "/Users/rodion/Documents/ato.mp4";
    static const TrackerType TRACKER_NAME = TrackerType::MEDIANFLOW;

    static const std::string WRONG_FILEPATH_ERROR = "TRACKING. [ERROR]: Incorrect file path! Abort.";
    static const std::string EMPTY_FRAME_ERROR = "READING FILE. [ERROR]: Empty frame! Abort.";
}

#endif //EXP4_CONSTANTS_H
