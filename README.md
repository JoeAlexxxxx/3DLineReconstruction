# 3D Line Reconstruction

This is a public repository for our paper: "Clustering, 
triangulation, 
and evaluation of 3D lines in multiple images".

## Install

Our code compiles and runs normally under VS2019, on the Windows11 system with CMake 3.24. 
We have provided the 
In order to achieve more efficient knn search, we need a GPU that supports CUDA.

- Locally compiled software and hardware environment
  - VisualStudio 2019
  - Windows11
  - CUDA 11.7
  - i9 12900K
  - Nvidia RTX3090

## Dependency

The compilation and operation of the program rely on some common open-source third-party libraries, but we also provide our own compiled library files.

- 3rd party

  | Library Name | Version |
  | ------------ | ------- |
  | Boost        | 1.79.0  |
  | Eigen        | 3.4.0   |
  | OpenCV       | 4.55    |
  | CUDA         | 11.7    |
  | OpenMP       |         |
  | TCLAP        | 1.4.0   |
  | NLOPT        | 2.7.1   |

- Private library

​	Download available in this repository, both debug and release versions are provided

## Example and test

In this repository, we also provide a complete dataset Castle30 for testing and also provide the line segments taken from DeepLSD. In the code, we use TCLAP as the controller for command input and provide a simple command parameter introduction. Here we will introduce the usage of these commands in detail and will give the method of testing experimental data later.

### Input command

```javascript
[3DLineResconstruction.exe] [-i] [inputfolder] [-l] [line extraction method] [-f] [line files extraction from other programs] [-e] [the file extension of the line files] [-c] [specifies whether the result comes from colmap] [-s] [the maximum size of input images] [-n] [the maximum number of input lines]
```

- Inputfolder `-i (std::string)` 

  This parameter cannot be empty. It specifies the folder where the image files and VisualSFM result nvm files are stored.

- Line extraction method `-l (int)`

  Specify the line segment extraction method. Three line segment extraction methods are embedded in the program: LSD(OpenCV version), AG3 Line and EDLine, corresponding to commands 1-3 respectively. If you want to use the line segment obtained by other programs, you can not use this command parameter or enter the value -1. 

- Line files folder `-f (std::string)`

  Specify the folder path where the line segment files are stored. If the line extraction method command `-l` is not used or -1, this command cannot be empty.

- Line file extension `-e (std::string)`

  Use the previous command `-f`. This command does not refer to the file extension alone, and it is used to help identify the pairing of line files and images. If the image name is `0001.jpg`, and the line file name `0001.line`, then the command input should be `.line`. If the line file name is `0001.jpg.line`, this command should be `.jpg.line`.

- From colmap `-c (int)`

  If the nvm file is from colmap, this command should be specified.

- Maximum image size `-s` and maximum line number `-n`

  These two commands are used to limit the maximum size of the image and the maximum number of line segments input. The default value is 99999, which means no limit.

### Example usage

```javascript
[3DLineResconstruction.exe] -i /yourPath/3DLineResconstruction/example/Castle30
/images/ -f /yourPath/3DLineResconstruction/example/Castle30
/lines/ -e .txt
```

### Result
![2024-08-09 13 56 14](https://github.com/user-attachments/assets/abd6b995-910c-4d82-af7e-986e4eaefafd)

![2024-08-09 13 56 49](https://github.com/user-attachments/assets/94b57979-b6eb-4e05-b77c-c918977f11d2)

### Addition

If you want to use your own line segment extraction results, you need to keep the line segment storage format consistent with the example file. In the example file, each line segment detected from the image is stored in a separate line. The two endpoints of the line segment are stored as four numbers separated by spaces, and no other characters are required. In order to maintain accuracy, these values are all float types and use the screen coordinate system, the origin of the coordinate system is in the upper left corner.

## Acknowledgement



## License

The source code of 3D line reconstruction is released under [GPLv2](http://www.gnu.org/licenses/old-licenses/gpl-2.0.html) license. For commercial use, please contact us.
