#ifndef FS_OPERATIONS
#define FS_OPERATIONS

#include <boost/filesystem.hpp>

#include "types.hpp"

namespace organizer
{
    DirEntries get_file_list( std::string const &folder_path );
    Date get_modification_time( Path const &path );
    std::string get_file_sha1( Path const &path );
} // namespace organizer

#endif
