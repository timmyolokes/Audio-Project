# Sound Visualizer

This repository contains code for a sound visualizer application built using the openFrameworks framework. The application provides a graphical representation of sound using various visual elements.

## Features

- Real-time visualization of sound spectrum
- Adjustable color, volume, and decay parameters
- Support for playing different sound files (drum, piano, trumpet, violin)
- Interactive graphical user interface (GUI) with sliders
- 3D visualization using camera perspective

## Installation

To run the sound visualizer application, follow these steps:

1. Clone the repository to your local machine using the following command:
git clone https://github.com/timmyolokes/Audio-Project.git

2. Install openFrameworks by following the instructions provided in the [openFrameworks documentation](https://openframeworks.cc/download/).

3. Once openFrameworks is installed, navigate to the `Audio-Project` directory and open the project in your preferred integrated development environment (IDE).

4. Build and run the project from within your IDE.

## Usage

- Upon running the application, you will see a graphical interface with sliders for adjusting the color, volume, and decay parameters. Use these sliders to customize the visual appearance and behavior of the sound visualizer.

- By default, the application starts playing a drum loop sound. You can press the following keys to switch between different sounds:
  - 'p' - Play a piano loop sound
  - 't' - Play a trumpet loop sound
  - 'd' - Play a drum loop sound
  - 'v' - Play a violin loop sound
  - 's' - Stop the sound

- The visualizer displays the sound spectrum using various graphical elements, such as spheres and rectangles. The size and shape of these elements correspond to the amplitudes of different frequency bands in the sound spectrum.

- The GUI provides information and instructions on how to use the sliders and play different sounds.

## Contributing

Contributions to this sound visualizer project are welcome. If you find any issues or have suggestions for improvements, please open an issue or submit a pull request.

## Acknowledgments

- The sound visualizer application is built using the openFrameworks framework.
- The project makes use of the [ofxGui](https://openframeworks.cc/documentation/ofxGui/) addon for creating the graphical user interface (GUI).
- The sound files used in the application are for demonstration purposes only and should be replaced with appropriate sound files for your use case.
