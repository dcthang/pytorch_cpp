# pix2pix
This is "pix2pix".<br>
Original paper: P. Isola, J.-Y. Zhu, T. Zhou, and A. A. Efros. Image-to-image translation with conditional adversarial networks. In Proceesings of the IEEE Conference on Computer Vision and Pattern Recognition, 2017. [link](https://openaccess.thecvf.com/content_cvpr_2017/html/Isola_Image-To-Image_Translation_With_CVPR_2017_paper.html)

## Usage

### 1. Build
Please build the source file according to the procedure.
~~~
$ mkdir build
$ cd build
$ cmake ..
$ make -j4
$ cd ..
~~~

### 2. Dataset Setting

#### Recommendation
- CMP Facade Database<br>
This is a dataset of facade images assembled at the Center for Machine Perception, which includes 606 rectified images of facades from various sources, which have been manually annotated.<br>
Link: [official](http://cmp.felk.cvut.cz/~tylecr1/facade/)

#### Setting

Please create a link for the dataset.<br>
You should substitute the path of training input data for "<training_input_path>".<br>
You should substitute the path of training output data for "<training_output_path>".<br>
You should substitute the path of test input data for "<test_input_path>".<br>
You should substitute the path of test output data for "<test_output_path>".<br>
The following is an example for "facade".
~~~
$ cd datasets
$ mkdir facade
$ cd facade
$ ln -s <training_input_path> ./trainI
$ ln -s <training_output_path> ./trainO
$ ln -s <test_input_path> ./testI
$ ln -s <test_output_path> ./testO
$ cd ../..
~~~

### 3. Training

#### Setting
Please set the shell for executable file.
~~~
$ vi scripts/train.sh
~~~
The following is an exmaple of the training phase.<br>
If you want to view specific examples of command line arguments, please view "src/main.cpp" or add "--help" to the argument.
~~~
#!/bin/bash

DATA='facade'

./pix2pix \
    --train true \
    --epochs 300 \
    --dataset ${DATA} \
    --size 256 \
    --loss "vanilla" \
    --batch_size 16 \
    --gpu_id 0 \
    --input_nc 3 \
    --output_nc 3
~~~

#### Run
Please execute the following to start the program.
~~~
$ sh scripts/train.sh
~~~

### 4. Test

#### Setting
Please set the shell for executable file.
~~~
$ vi scripts/test.sh
~~~
The following is an exmaple of the test phase.<br>
If you want to view specific examples of command line arguments, please view "src/main.cpp" or add "--help" to the argument.
~~~
#!/bin/bash

DATA='facade'

./pix2pix \
    --test true \
    --dataset ${DATA} \
    --size 256 \
    --gpu_id 0 \
    --input_nc 3 \
    --output_nc 3
~~~
There are no particular restrictions on both input and output images.<br>
However, the two file names must correspond without the extension.

#### Run
Please execute the following to start the program.
~~~
$ sh scripts/test.sh
~~~

