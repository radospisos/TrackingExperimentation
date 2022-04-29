//
// Created by Rodion Shyshkin on 29.04.2022.
//

#include <gtest/gtest.h>
#include <core/trackers/kcf.h>

class KCFTest : public ::testing::Test {

};

TEST_F(KCFTest, KCFCreation) {
    EXPECT_NO_THROW(auto kcf = KCF());
}

TEST_F(KCFTest, KCFinitialization) {
    auto kcf = KCF();
    cv::Rect2d rect = cv::Rect2d(1, 1, 600, 500);
    cv::Mat frame = cv::Mat(300, 400, CV_64F);
    EXPECT_THROW(kcf.init(rect, cv::Mat(400, 300, CV_64F)), std::invalid_argument);
    EXPECT_THROW(kcf.init(rect, cv::Mat(400, 602, CV_64F)), std::invalid_argument);
    EXPECT_THROW(kcf.init(rect, cv::Mat(502, 300, CV_64F)), std::invalid_argument);
    EXPECT_NO_THROW(kcf.init(rect, cv::Mat(502, 602, CV_64F)));
}

TEST_F(KCFTest, KCFupdating) {
    auto kcf = KCF();
    cv::Rect2d rect = cv::Rect2d(1, 1, 600, 500);
    cv::Mat frame = cv::Mat(800, 900, CV_64F);
    kcf.init(rect, frame);
    EXPECT_THROW(kcf.update( cv::Mat(700, 900, CV_64F)), std::invalid_argument);
    EXPECT_THROW(kcf.update(cv::Mat(800, 300, CV_64F)), std::invalid_argument);
    EXPECT_THROW(kcf.update(cv::Mat(500, 1000, CV_64F)), std::invalid_argument);
    EXPECT_NO_THROW(kcf.update(cv::Mat(800, 900, CV_64F)));
}