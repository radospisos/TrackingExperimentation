//
// Created by Rodion Shyshkin on 29.04.2022.
//
#include <gtest/gtest.h>
#include <core/result_structures/correction_controller.h>

class KCFTest : public ::testing::Test {

};

TEST_F(KCFTest, ControllerCreation) {
    CorrectionController controller = CorrectionController::create(false, false, false, false);
    EXPECT_NO_THROW(controller = CorrectionController::create(true, false, true, false));
    EXPECT_NO_THROW(controller = CorrectionController::create(true, false, false, true));
    EXPECT_NO_THROW(controller = CorrectionController::create(false, true, true, false));
    EXPECT_NO_THROW(controller = CorrectionController::create(false, true, false, true));
    EXPECT_NO_THROW(controller = CorrectionController::create(true, false, false, false));
    EXPECT_NO_THROW(controller = CorrectionController::create(false, true, false, false));
    EXPECT_NO_THROW(controller = CorrectionController::create(false, false, true, false));
    EXPECT_NO_THROW(controller = CorrectionController::create(false, false, false, true));

    EXPECT_THROW(controller = CorrectionController::create(true, true, true, true), std::invalid_argument);
    EXPECT_THROW(controller = CorrectionController::create(true, true, false, true), std::invalid_argument);
    EXPECT_THROW(controller = CorrectionController::create(true, true, true, false), std::invalid_argument);
    EXPECT_THROW(controller = CorrectionController::create(true, true, false, false), std::invalid_argument);
    EXPECT_THROW(controller = CorrectionController::create(true, false, true, true), std::invalid_argument);
    EXPECT_THROW(controller = CorrectionController::create(false, true, true, true), std::invalid_argument);
    EXPECT_THROW(controller = CorrectionController::create(false, false, true, true), std::invalid_argument);
}