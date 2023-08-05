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

First things first here is what the 14 byte 
BITMAPFILEHEADER
struct looks like:

typedef struct
{
    WORD bfType;
    DWORD bfSize;
    WORD bfReserved1;
    WORD bfReserved2;
    DWORD bfOffBits;
}
BITMAPFILEHEADER;

WORD AND DWORD are both primitives,

WORD is a 16bit unsigned integer value ranging 
from values of 0 to 65,535, it is unsigned meaning 
it cannot represent negative numbers

DWORD (or "double WORD") is a 32bit unsigned 
integer value ranging from values of 0 to 4,294,
967,295, it is unsigned meaning it cannot 
represent negative numbers

bfType determines the "type" of the file (being
always in this case BMP)

bfSize represents the size in bytes of the bmp
files (including the metadata)

bfReserved1 and bfReserved2 are always the value 
of 0

bfOffBits is the offset in bytes from the 
beggining of BITMAPFILEHEADER struct to the actual 
bitmap (how many bytes after this struct the 
actual bitmap begins which in this case will be 40 
more bytes because of the next struct).

next we have BITMAPINFOHEADER

typedef struct
{
    DWORD  biSize;
    LONG   biWidth;
    LONG   biHeight;
    WORD   biPlanes;
    WORD   biBitCount;
    DWORD  biCompression;
    DWORD  biSizeImage;
    LONG   biXPelsPerMeter;
    LONG   biYPelsPerMeter;
    DWORD  biClrUsed;
    DWORD  biClrImportant;
}
BITMAPINFOHEADER;

biSize is the number of bytes of the struct

biWidth is the width of the bitmap, in pixels (not 
bytes, but pixels remember each pixel takes up 3 
bytes)

biHeight is the height of the bitmap in pixels, if 
biHeight is positive, the bitmap is a bottom-up 
DIB and its origin is the lower-left corner. if 
biHeight is negative the bitmap is a topdown DIB 
and its origin the the upper-left corner.

biPlanes is the number of planes for the target 
device (must always be 1)

biBitCount is the number of bits per pixel, this 
number determines the number of bits that define 
each pixel, given we are using the RGB format this 
number will be 24 in this case.

biCompression is the type of compression for a 
compressed bottom-up bitmap (dont need to worry 
about this)

biSizeImage is the size in bytes of the image 
(note not the pixels but the total size of just 
the image not the metadata)

biXPelsPerMeter is the horizontal resolution in 
pixels per meter of the device the image is 
displayed on

biYpelsPerMeter is the vertical resolution in 
pixels per meter of the device the image is 
displayed on

biClrUsed is the number of color indexes in the 
color table that are actually used by the bitmap, 
if the value is 0 the bitmap uses the maximum 
number of colors corresponding to the value of 
biBitCount member for the compression mode 
specified by biCompression.

biClrImportant is the number of color indexes that 
are required for displaying the bitmap. if the 
value is zero, all colors are required.


RGBTRIPLE

and of course there are the pixels in this actual
image which are represented by rgb triple which
is a 3byte struct each primitive value having 256 
variations explained above in this document

typedef struct
{
    BYTE  rgbtBlue;
    BYTE  rgbtGreen;
    BYTE  rgbtRed;
}
RGBTRIPLE;

BYTE as a datastructure is just an unsigned byte 
as the name suggests ranging from values between 0 
and 255

IMAGE FILTERING(GRAYSCALE)

if a pixels red green and blue values all have a 
value of 0x00 the pixel is white, if they have all 
values set to 0xff, the pixel is white, so long as 
all of the pixels red, green and blue values are 
all equal then the pixel will be varying shades of 
grey.

to convert a pixel to grayscale we just need to 
make sure the red, green and blue values are all 
the same value, we do this by taking the average 
of the red green and blue values and apply that 
value to red green and blue to make the new pixel

IMAGE FILTERING(REFLECTION)

IMAGE FILTERING(BLUR)

IMAGE FILTERING (EDGES)