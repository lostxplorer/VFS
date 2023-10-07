#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "FileSystemManager.h"
#include "ExecutableCommands.h"
#include "Parser.h"
#include "FilesystemOperations.h"
#include "Directory.h"
#include "IFile.h"

using ::testing::_;
using ::testing::Return;


class MockCommand : public ExecutableCommands {
public:
    MOCK_METHOD(bool, cd, (const std::string& directory), (override));
    MOCK_METHOD(bool, find, (const std::string& directory));
};

TEST(MkdirTest, MockCdAndFind) {
    MockCommand mockCommand;  // Create a mock object
    
    // Set expectations for cd and find functions
    EXPECT_CALL(mockCommand, cd("dir1"))
        .Times(1)
        .WillOnce(Return(true));
    
    EXPECT_CALL(mockCommand, cd(".."))
        .Times(1)
        .WillOnce(Return(true));

    // Create your Parser instance with the mockCommand
    Parser parser;

    // Prepare input_commands for testing
    std::vector<std::string> input_commands = {"mkdir", "dir1/dir2"};

    // Call the mkdir function you want to test
    
    mkdir(mockCommand, parser, input_commands);
}


int main(int argc, char **argv)
{
    testing::InitGoogleMock(&argc, argv);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}