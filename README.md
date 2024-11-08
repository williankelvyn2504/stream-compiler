# Video to HLS Converter

This is a simple C++ program that converts a video file (MP4, MKV, etc.) into an HLS (HTTP Live Streaming) format. The program uses FFmpeg to generate the `.m3u8` playlist file and segment the video into smaller chunks for streaming.

## Features
- Converts video files into HLS format.
- Creates an output folder if it doesn't exist.
- Checks if the input file exists and if the output folder is valid.
- Uses FFmpeg to perform the conversion.

## Requirements
- **FFmpeg**: Make sure FFmpeg is installed on your system. You can download it from [FFmpeg official website](https://ffmpeg.org/download.html).
- **C++17**: The program uses C++17 features, so make sure you're using a compatible compiler (e.g., GCC 7.0 or higher).

## How to Run

1. Clone this repository or download the source code.
2. Ensure that FFmpeg is installed on your system and available in your system's PATH.
3. Compile the code using a C++17 compatible compiler:
   ```bash
   g++ -o video_to_hls main.cpp
   ```

4. Run the program:

   ```bash
   ./video_to_hls
   ```
   
## Example:

   ```bash
   Enter the path of the input file: /path/to/video.mp4
   Enter the output folder path: /path/to/output/folder
   ```
   
After the conversion is complete, you'll see a message indicating that the M3U8 file was generated at the specified output folder.

## How It Works

1. The program first checks if the input file exists.

2. It checks if the output folder exists:
If it doesn't exist, the program creates it.
If it exists but is not a folder, an error message is shown.

3. The video is processed using FFmpeg to create HLS files:
The main .m3u8 playlist file is generated.
Video segments are created and saved in the output folder.

## Customization

You can modify the FFmpeg command in the convertToHLS function to change encoding options, output resolution, or other FFmpeg parameters to suit your needs.

Troubleshooting

Input file not found: Make sure the file path is correct and the video file exists.

The specified output folder is not a folder: Ensure the path is a valid directory and not a file.
