#!/bin/bash

rm -rf Left_Image
rm -rf Right_Image
mkdir Left_Image
mkdir Right_Image

# Moving the left Images in the Left SubFolder
for f in *left.jpg;
 do echo "Processing $f file..";
    mv $f . Left_Image/
done

ls Left_Image > list_left_camera.txt
mv list_left_camera.txt . ../

# Moving the left Images in the Left SubFolder
for f in *right.jpg;
  do echo "Processing $f file..";
     mv $f . Right_Image/
done

ls Right_Image > list_right_camera.txt
mv list_right_camera.txt . ../

