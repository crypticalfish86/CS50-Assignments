Below is a picture of a smiley face below 
represented in bits:

1 1 0 0 0 0 1 1
1 0 1 1 1 1 0 1
0 1 0 1 1 0 1 0
0 1 1 1 1 1 1 0
0 1 0 1 1 0 1 0
0 1 1 0 0 1 1 0
1 0 1 1 1 1 0 1
1 1 0 0 0 0 1 1

The 1s represent white pixels and the 0s represent
black pixels

you can see the smiley face attached as 
2bit_smiley_bitmap.png in this directory.


All images essentially are this, just a bitmap, a
collection of bits/bytes arranged to determine the
composition of the image as well as the height, 
width and other properties of the image that is 
stored in the images "metadata".

The smiley image above is an example of a 2bit image where each pixel only has 2 possible values
0 or 1, however modern images are much more complex
and can represent a broader range of colours than 
just white and black.

Modern images are made up of 3 bytes (24 bits), 1 
bit to determine the amount of red, one bit to 
determine the amount of green and one bit to 
determine the amount of blue. these 3 bytes as 
opposed to a 2 bit image allow modern computers to 
represent a variation of 16,777,216 different 
possible colours per pixel (256^3 variations 
because one byte has 256 variations and there are 
3 bytes), this format is called RGB (red green 
blue) and is the most common form of graphical 
representation in the modern day. All image files are represented this way from BMP to JPEG to PNG

BMP FILES AND FORMAT

BMP files (bitmap files) are a modern form of 
imaging software, however each byte is represented 
in a BGR format instead of RGB (meaning the blue 
byte comes first then green then red) this means 
to represent pure red in a BMP file a pixel would 
have these values 0000ff (remember ff in 
hexidecimal means 256) the first 00 representing 
the amount of blue, the second 00 representing the 
amount of green and the ff representing the amount 
of red, here is the same as a pure green pixel: 
00ff00, and a pure blue: ff0000.

BMP files begin with metadata called "headers" 
which represents information and composition of 
the image such as the width, height, format, 
number of bits/bytes per pixel. 

There are 2 headers containing metadata in a bmp 
file the first one is called BITMAPFILEHEADER 
which is 14 bytes long, the second of these is 
called BITMAPINFOHEADER which is 40 bytes long. 
the remaining bytes of the file is the actual 
bitmap and image. Meaning the first 54 bytes of a 
BMP file is metadata with information on the 
image, and the remaining bytes are the image 
itself.

So before the metadata the image is just a bunch of bytes in a line in computer memory:

0xff0x0f0x6a0x04 etc etc.


but once the metadata has been interpreted and the 
width, height, composition and format has been 
determine the image takes actual shape for example 
below is a 4 by 3 image (the width and height of 
which is declared in the metadata):

0xff 0xa1 etc. for 54 bytes then the image: 
            ffffff 00af00 000ff0 ba0f00
            00ff00 00ff00 00aff0 00ff00
            00ff00 a2f4b9 99ff00 00ff00

a full image of the smiley face that has been 
turned red is represented in 
24bit_red_smiley_bitmap.png this smiely is 
a 24bit 8 by 8 smiley, remember ffffff represents
white and 0000ff represents pure red because a 
BMP file uses a BGR format.

Notice that these BMP files can be represented as a
2 dimensional array of pixels: where the image is 
an array of rows, each row is an array of pixels, 
this is how we can represent a 2d image.

e.g. the bitmap of the four by 3 image can be represented like this:

[
    [ffffff, 00af00, 000ff0, ba0f00], 
    [00ff00, 00ff00, 00aff0, ba0f00], 
    [00ff00, a2f4b9, 99ff00, 00ff00]
]

for example if we wanted the last pixel in the 
bottom right we would do image[2][3] (remember 
arrays start at 0).

BMP METADATA



IMAGE FILTERING(GRAYSCALE)

IMAGE FILTERING(REFLECTION)

IMAGE FILTERING(BLUR)

IMAGE FILTERING (EDGES)