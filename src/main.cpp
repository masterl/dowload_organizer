#include <iostream>
#include <string>

#include "directory_processors.hpp"
#include "fs_operations.hpp"
#include "generators.hpp"
#include "validators.hpp"

namespace org = organizer;

int main()
{
    std::string const folder_path{"/home/leonardo/Downloads"};

    try
    {
        org::ensure_path_is_a_folder( folder_path );

        DestFolders const dest_folders = org::create_dest_folders( folder_path );

        auto file_list = org::get_file_list( folder_path );

        org::process_images( dest_folders.at( "images" ), file_list );
        org::process_compressed( dest_folders.at( "compressed" ), file_list );
        org::process_audios( dest_folders.at( "audios" ), file_list );
        org::process_pdfs( dest_folders.at( "pdfs" ), file_list );
        org::process_documents( dest_folders.at( "documents" ), file_list );
        org::process_sources( dest_folders.at( "sources" ), file_list );
    }
    catch( std::exception &error )
    {
        std::cerr << error.what() << "\n";
    }

    return 0;
}
