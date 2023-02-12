# cub3d

cub3d is a 3D graphics engine that uses raycasting technology to create and display 3D graphics in a terminal window.

Raycasting is a rendering technique used to generate 2D images from 3D environments. It works by simulating the path of light rays as they pass through the 3D world and intersect with objects. By calculating the intersection points and the colors of the objects at these points, it is possible to generate a 2D image that appears to be 3D.

# Table of Contents

1. <a href="#installation"> Installation 
1. <a href="#usage"> Usage 
1. <a href="#map"> Map
1. <a href="#gameplay"> Gameplay
1. <a href="#license"> license 

## <span id="installation"> Installation
### macOS

To install cub3d on macOS, you will need to have the following dependencies installed:

+ Xcode Command Line Tools
+ SDL2

To install the Xcode Command Line Tools, open a terminal and run the following command:

```
xcode-select --install
```

To install SDL2, you can use Homebrew by running the following command:

```
brew install sdl2
```

Once the dependencies are installed, clone the repository and build the project by running the following commands:

```
git clone https://github.com/osman-selim-yalcin/cub3d.git
cd cub3d
make
```

### Debian-based systems (such as Ubuntu)

To install cub3d on a Debian-based system (such as Ubuntu), you will need to have the following dependencies installed:

+ GCC
+ Make
+ SDL2

To install these dependencies, run the following command:

```
sudo apt-get install build-essential libsdl2-dev
```

Once the dependencies are installed, clone the repository and build the project by running the following commands:

```
git clone https://github.com/osman-selim-yalcin/cub3d.git
cd cub3d
make
```

## <span id="usage"> Usage

To run cub3d, use the following command:

```
./cub3d map.cub
```

where map.cub is the path to a map file. The map file should contain a description of the 3D world, including the position of walls and objects.

## <span id="map">  Changing the Map

To change the map in cub3d, you will need to create a new map file and specify its path when running the cub3d command. The map file should contain a description of the 3D world, including the position of walls and objects.

The map file should follow these rules:

+ V: Enemy spawn point
+ E/N/S/W: Player spawn point and initial direction
+ C: Closed door
+ 1: Wall
+ 0: Empty area

## <span id="gameplay">  Gameplay

In cub3d, you have 4 lives. You can use the following keys to control your character:

    M: Scale up/down the map
    left click: Attack
    E: Open wall
    A/W/S/D: Movement
    up/down/right/left: Change direction
    Mouse rotation is also available

## Contributior

I devoloped this project with [Burak Mat](https://github.com/burakmat)

## <span id="license">  License

cub3d is licensed under the [MIT](https://github.com/osman-selim-yalcin/cub3d/blob/main/LICENSE) License.
