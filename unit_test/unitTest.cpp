// #include <gtest/gtest.h>

// #include "ExecutableCommands.h"
// #include "Directory.h"
// #include "IFile.h"

// class CommandsTest : public ::testing::Test 
// {
// protected:
//     Commands commands;
// };

// TEST_F(CommandsTest, MkdirTest)
// {
//     commands.mkdir("test_dir");
//     std::shared_ptr<Directory> dir = commands.get_current_directory()->find_directory("test_dir");
//     ASSERT_TRUE(dir != nullptr);
// }

// TEST_F(CommandsTest, MkdirDuplicateTest) {
//     commands.mkdir("test_dir");
//     testing::internal::CaptureStdout();
//     commands.mkdir("test_dir");
//     std::string output = testing::internal::GetCapturedStdout();
//     ASSERT_EQ(output, "Error: Directory 'test_dir' already exists.\n");
// }

// TEST_F(CommandsTest, RmdirTest)
// {
//     commands.mkdir("test_dir");
//     commands.rmdir("test_dir");
//     std::shared_ptr<Directory> dir = commands.get_current_directory()->find_directory("test_dir");
//     ASSERT_TRUE(dir == nullptr);
// }

// TEST_F(CommandsTest, RmdirNonExistentTest) {
//     testing::internal::CaptureStdout();
//     commands.rmdir("non_existent_dir");
//     std::string output = testing::internal::GetCapturedStdout();
//     ASSERT_EQ(output, "Error: Directory 'non_existent_dir' not found.\n");
// }

// TEST_F(CommandsTest, PwdTest)
// {
//     testing::internal::CaptureStdout();
//     commands.pwd();
//     std::string output = testing::internal::GetCapturedStdout();
//     ASSERT_EQ(output, "/");
// }

// TEST_F(CommandsTest, CdTest)
// {
//     commands.mkdir("test_dir");
//     commands.cd("test_dir");
//     std::string currentPath = commands.get_current_directory()->get_name();
//     ASSERT_EQ(currentPath, "test_dir");
// }

// TEST_F(CommandsTest, CdTosuper_directoryTest) {
//     commands.mkdir("test_dir");
//     commands.cd("test_dir");
//     commands.cd("..");
//     std::string currentPath = commands.get_current_directory()->get_name();
//     ASSERT_EQ(currentPath, "/");
// }

// TEST_F(CommandsTest, CdInvalidDirectoryTest)
// {
//     testing::internal::CaptureStdout();
//     commands.cd("non_existent_dir");
//     std::string output = testing::internal::GetCapturedStdout();
//     ASSERT_EQ(output, "Error: Directory 'non_existent_dir' not found.\n");
// }

// TEST_F(CommandsTest, LsTest)
// {
//     commands.mkdir("test_dir");
//     testing::internal::CaptureStdout();
//     commands.ls();
//     std::string output = testing::internal::GetCapturedStdout();
//     ASSERT_EQ(output, "test_dir [Directory]\n");
// }

// TEST_F(CommandsTest, TouchTest)
// {
//     commands.touch("test_file.txt");
//     std::shared_ptr<IFile> file = commands.get_current_directory()->find_file("test_file.txt");
//     ASSERT_TRUE(file != nullptr);
// }

// TEST_F(CommandsTest, TouchDuplicateTest)
// {
//     commands.touch("test_file.txt");
//     testing::internal::CaptureStdout();
//     commands.touch("test_file.txt");
//     std::string output = testing::internal::GetCapturedStdout();
//     ASSERT_EQ(output, "Error: File 'test_file.txt' already exists.\n");
// }

// TEST_F(CommandsTest, FindTest)
// {
//     commands.mkdir("test_dir");
//     commands.cd("test_dir");
//     commands.touch("test_file.txt");
//     testing::internal::CaptureStdout();
//     commands.find("test_file.txt");
//     std::string output = testing::internal::GetCapturedStdout();
//     ASSERT_EQ(output, "File 'test_file.txt' found at path: /test_dir/\n");
// }

// TEST_F(CommandsTest, RmTest)
// {
//     commands.touch("test_file.txt");
//     std::shared_ptr<IFile> file = commands.get_current_directory()->find_file("test_file.txt");
//     commands.rm("test_file.txt");
//     file = commands.get_current_directory()->find_file("test_file.txt");
//     ASSERT_TRUE(file == nullptr);
// }

// TEST_F(CommandsTest, RmNonExistentFileTest)
// {
//     testing::internal::CaptureStdout();
//     commands.rm("non_existent_file.txt");
//     std::string output = testing::internal::GetCapturedStdout();
//     ASSERT_EQ(output, "Error: File 'non_existent_file.txt' not found.\n");
// }

// int main(int argc, char **argv)
// {
//     testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }


#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "ExecutableCommands.h" 

using namespace ::testing;

class MockDirectory : public Directory {
public:
    MockDirectory(const std::string& name) : Directory(name) {}
    MOCK_METHOD(bool, remove_file_system_component, (const std::string&));
};

class MockFileSystemManager : public FileSystemManager {
public:
    MockFileSystemManager() {
        root = std::make_shared<MockDirectory>("/");
        current_directory = root;
        current_path = "/";
    }
};

class ExecutableCommandsTest : public Test {
public:
    ExecutableCommandsTest() {
        fileSystemManager = std::make_shared<MockFileSystemManager>();
        executableCommands = std::make_unique<ExecutableCommands>();
    }

protected:
    std::shared_ptr<MockFileSystemManager> fileSystemManager;
    std::unique_ptr<ExecutableCommands> executableCommands;
};

TEST_F(ExecutableCommandsTest, MkdirTest) {
    auto mockDirectory = std::make_shared<MockDirectory>("test_dir");

    EXPECT_CALL(*fileSystemManager->current_directory, add_file_system_component(mockDirectory))
        .WillOnce(Return());

    executableCommands->mkdir("test_dir");
}

TEST_F(ExecutableCommandsTest, RmdirTest) {
    EXPECT_CALL(*fileSystemManager->current_directory, remove_file_system_component("test_dir"))
        .WillOnce(Return(true));

    bool result = executableCommands->rmdir("test_dir");

    ASSERT_TRUE(result);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}