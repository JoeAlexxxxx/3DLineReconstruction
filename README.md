# 3D Line Reconstruction

This is a public repository for our paper: "Clustering, 
triangulation, 
and evaluation of 3D lines in multiple images".

  | Source file | Description |
  | ------------ | ------- |
  | Main_SfM.cpp        | Main function, make obj files   |
  | LineSweep.cpp, LineCluster.cpp | Implementation of the adaptive line clustering   |
  | triangulated3Dlines.cpp       | Implementation of the triangulation with geometry consistence    |

## Features
Accurate 3D line segment clustering  with the support of a probability model.
Robust triangulation is achieved by a universal framework that refines the 3D line with various forms of geometric consistency.
  
## Install
- One can use 3DLineResconstruction_code/CMakeLists.txt 
to compile this repository with CMake.
- It was compiled and ran normally under VS2019, on the Windows11 system with CMake 3.24. 
- It needs a GPU to achieve efficient knn search.
- The line matching method is implemented based on <br>
  `ELSR: Efficient Line Segment Reconstruction with Planes and Points Guidance CVPR, 2022.`<br>
​	Both debug and release versions are provided in "3DLineResconstruction_Lib".

- Locally compiled software and hardware environment
  - VisualStudio 2019
  - Windows11
  - CUDA 11.7
  - i9 12900K
  - Nvidia RTX3090

## Dependency

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



## Usage
- The algorithm require the SfM result named "res.nvm" from either ColMap or VisualSfM.
  "res.nvm" must be in the image folder.
- We provide the dataset of Castle30 for test.
- We use TCLAP for command input and provide the introduction of parameters. 

### Input command

```javascript
[3DLineResconstruction.exe] [-i] [inputfolder] [-l] [line extraction method] [-f] [line files extraction from other programs] [-e] [the file extension of the line files] [-c] [specifies whether the result comes from colmap] [-s] [the maximum size of input images] [-n] [the maximum number of input lines]
```

- Inputfolder `-i (std::string)` 

  This parameter cannot be empty. It specifies the folder where the image files and VisualSFM result nvm files are stored.

- Line extraction method `-l (int)`

  Specify the line segment extraction method. Three line segment extraction methods are embedded in the program: <u>LSD(OpenCV version)</u>, <u>AG3Line</u> and <u>EDLine</u>, corresponding to commands 1-3 respectively. If you want to use the line segment obtained by other programs, you can not use this command parameter or enter the value -1. 

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
