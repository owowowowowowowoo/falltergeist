#pragma once

#include "../VFS/IDriver.h"
#include "../VFS/IFile.h"
#include <filesystem>

namespace Falltergeist {
    namespace VFS {
        class NativeDriver final : public IDriver {
        public:
            NativeDriver(const std::filesystem::path& basePath);

            bool exists(const std::string& path) override;

            std::shared_ptr<IFile> open(const std::string& path, IFile::OpenMode mode) override;

        private:
            std::filesystem::path _basePath;
        };
    }
}
