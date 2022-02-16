#include <string>

int main()
{
    const std::string filename = "../../scripts/create_json_files_with_data.py";
    std::string command = "python3 ";
    command += filename;
    system(command.c_str());

    return 0;
}