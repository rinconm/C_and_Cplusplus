# This shell script was taken from ~eecs22/bin/pnmtojpeg_hw2.tcsh to
# review how PPM images were converted to JPEG for HW2: PhotoLab

### THIS NEEDS TO BE REVISED:  (RD, 10/25/17)
# 1. somehow this fails when user has 'bash' as shell
# 2. should not be 'tcsh', should be 'sh' script
# 3. the .ppm extension handling needs to be cleaned up

# WAS: modified by Huan Chen, 10/03/2016, for EECS 22 hw2

# This script is specialized for eecs10 homework 7
# It takes one argument the file name (file stem only)
# - if ~/public_html does not exist, create it
# - file is moved to image.ppm
# - file is converted to jpg in ~/public_html
# -  chmod ~/public_html/<file>.jpg

# set the library path so that the pnmtojpg finds its libraries
setenv LD_LIBRARY_PATH /dcs/packages/Xlocal/lib

# get the home directory, do not rely on variable HOME, it may
# not been set (who knows ...). use the cd command instead 
set HOME_DIR=`cd; pwd`
if ( $HOME_DIR == "" ) then
    echo Failed to get home directory
    if ( -d ../public_html ) then
	echo Assume: ../public_html
	set HTML_DIR="../public_html"
    else 
	exit 1
    endif
else
    # dir to place converted pictures 
    set HTML_DIR="$HOME_DIR/public_html"
endif 

# get just the file name of the argument
set T_FNAME=`basename $1 .ppm`

# template html file for holding the output images
set TEMPLATE_HTML="~eecs22/public_html/index_hw2.html"
set INPUT_IMAGE="EngPlaza"

# hw3: unconditionally create a new index.html
# to overwrite hw2 version (RD, 10/25/17)
mkdir -p $HTML_DIR
chmod 755 $HTML_DIR
cp $TEMPLATE_HTML $HTML_DIR/index.html
chmod 755 $HTML_DIR/index.html

# call the conversion 
pnmtojpeg $1 > $HTML_DIR/$T_FNAME.jpg
chmod 644 $HTML_DIR/$T_FNAME.jpg

# update input image as well in image selecting stage
pnmtojpeg $INPUT_IMAGE.ppm > $HTML_DIR/$INPUT_IMAGE.jpg
chmod 644 $HTML_DIR/$INPUT_IMAGE.jpg