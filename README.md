# cub3d

cub3d is a 3D graphics engine that uses raycasting technology to create and display 3D graphics in a terminal window.

Raycasting is a rendering technique used to generate 2D images from 3D environments. It works by simulating the path of light rays as they pass through the 3D world and intersect with objects. By calculating the intersection points and the colors of the objects at these points, it is possible to generate a 2D image that appears to be 3D.

To install cub3d, you will need to have the following dependencies installed:

    GCC
    Make
    SDL2

To install these dependencies on a Debian-based system (such as Ubuntu), run the following command:

sudo apt-get install build-essential libsdl2-dev

Once the dependencies are installed, clone the repository and build the project by running the following commands:

git clone https://github.com/osman-selim-yalcin/cub3d.git
cd cub3d
make



Usage

To run cub3d, use the following command:

./cub3d [options] map.cub

where map.cub is the path to a map file. The map file should contain a description of the 3D world, including the position of walls and objects.

Contributing

If you'd like to contribute to the development of cub3d, please follow the contributing guidelines.
License

cub3d is licensed under the MIT License.
