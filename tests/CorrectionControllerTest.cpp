//
// Created by Rodion Shyshkin on 29.04.2022.
//
#include <gtest/gtest.h>
#include <core/result_structures/correction_controller.h>

class KCFTest : public ::testing::Test {

};

TEST_F(KCFTest, ControllerCreation) {
    CorrectionController controller;
    EXPECT_NO_THROW(controller = CorrectionController(-1.0, -1.0));
    EXPECT_NO_THROW(controller = CorrectionController(-1.0, 0.0));
    EXPECT_NO_THROW(controller = CorrectionController(-1.0, 1.0));
    EXPECT_NO_THROW(controller = CorrectionController(0.0, -1.0));
    EXPECT_NO_THROW(controller = CorrectionController(0.0, 0.0));
    EXPECT_NO_THROW(controller = CorrectionController(0.0, 1.0));
    EXPECT_NO_THROW(controller = CorrectionController(1.0, -1.0));
    EXPECT_NO_THROW(controller = CorrectionController(1.0, 0.0));
    EXPECT_NO_THROW(controller = CorrectionController(1.0, 1.0));
}