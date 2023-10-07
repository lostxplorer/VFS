#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "FileSystemManager.h"
#include "ExecutableCommands.h"
#include "Directory.h"
#include "IFile.h"

using ::testing::_;
using ::testing::Return;


class MockExecutableCommands : public FileSystemManager
{
    public:
    MOCK_METHOD(bool, find, (const std::string&));
};

using ::testing::_;
using ::testing::Return;

class MkdirTest : public ::testing::Test {
protected:
    MockExecutableCommands mockCommand;
    // Other necessary setup for your test
};

TEST_F(MkdirTest, FindReturnsTrue) {
    // Arrange
    const std::string directoryName = "existing_directory";
    ExecutableCommands command;
    EXPECT_CALL(mockCommand, find(directoryName)).WillOnce(Return(true));

    EXPECT_TRUE(command.rmdir("existing_directory"));
}

TEST_F(MkdirTest, FindReturnsFalse) {
    // Arrange
    const std::string directoryName = "non_existing_directory";
    ExecutableCommands command;
    EXPECT_CALL(mockCommand, find(directoryName)).WillOnce(Return(false));

    // Act
    // Call your mkdir function that uses the mockCommand object
    EXPECT_TRUE(command.rmdir("existing_directory"));

    // Assert
    // Add your assertions here
}



int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}