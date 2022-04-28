//
// Created by Rodion Shyshkin on 28.04.2022.
//

#ifndef EXP4_TRACKER_CREATOR_H
#define EXP4_TRACKER_CREATOR_H

#include <map>
#include <core/trackers/medianflow.h>
#include <core/trackers/kcf.h>
#include <utils/tracker_type.h>

namespace tracker_creator {
    static std::map<TrackerType, std::unique_ptr<Tracker>> trackers_map() {
        std::map<TrackerType, std::unique_ptr<Tracker>> result;
        result[TrackerType::MEDIANFLOW] = std::make_unique<MedianFlow>();
        result[TrackerType::KCF] = std::make_unique<KCF>();
        return result;
    }

    static std::unique_ptr<Tracker> create(const TrackerType& tracker_type) {
        auto trackers = trackers_map();
        if(trackers.find(tracker_type) != trackers.end()) {
            return std::move(trackers.at(tracker_type));
        }
        else throw std::out_of_range("Fatal Error! This type of core is not supported.");
    }
}

#endif //EXP4_TRACKER_CREATOR_H
