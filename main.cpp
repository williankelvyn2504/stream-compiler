#include<cstdlib>
#include<string>
#include<iostream>
#include<filesystem>

void convertToHLS(const std::string &inputFile, const std::string &outputDir) {
  if(!std::filesystem::exists(inputFile)) {
    std::cout << "Input file not found." << std::endl;
    return;
  }
  
  if(!std::filesystem::exists(outputDir)) {
    std::filesystem::create_directory(outputDir);
  } else {
    if(!std::filesystem::is_directory(outputDir)) {
      std::cout << "The specified output folder is not a folder." << std::endl;
      return;
    }
  }

  std::string ffmpegCommand = "ffmpeg -i \"" + inputFile + "\" -profile:v baseline -level 3.0 -s 1280x720 -start_number 0 -hls_time 10 -hls_list_size 0 -f hls \"" + outputDir + "/output.m3u8\"";

  int result = system(ffmpegCommand.c_str());

  if(result == 0) {
    std::cout << "Conversion succesful! M3U8 file generated at: " + outputDir + "/output.m3u8" << std::endl;
  } else {
    std::cerr << "Error executing FFmpeg!" << std::endl;
    return;
  }
}

int main() {
  std::string inputFile, outputDir;

  std::cout << "Enter the path of the input file: " << std::endl;
  std::getline(std::cin, inputFile);

  std::cout << "Enter the output folder path: " << std::endl;
  std::getline(std::cin, outputDir);

  convertToHLS(inputFile, outputDir);
  return 0;
}
