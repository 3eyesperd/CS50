/****************************************************************************
 * copy.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Copies a BMP piece by piece, just because.
 ***************************************************************************/
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: resize n input output\n");
        return 1;
    }

    // remember filenames
    char* infile = argv[2];
    char* outfile = argv[3];
    int n = atoi(argv[1]);

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }


    // determine padding (in bytes) for scanlines
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    //int padding_pixels = padding/(sizeof(RGBTRIPLE));

    //resize outfile's headers

    BITMAPINFOHEADER bi_output = bi;
    BITMAPFILEHEADER bf_output = bf;

    bi_output.biHeight = bi.biHeight*n;
    bi_output.biWidth = bi.biWidth*n;
    int padding_output =  (4 - (bi_output.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int padding_output_pixels = padding_output/(sizeof(RGBTRIPLE));
    bi_output.biSizeImage = sizeof(RGBTRIPLE)*((abs(bi_output.biHeight)))*((bi_output.biWidth)) + padding_output*(abs(bi_output.biHeight));
    bf_output.bfSize = bf_output.bfOffBits + bi_output.biSizeImage;



    // write outfile's BITMAPFILEHEADER
    fwrite(&bf_output, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi_output, sizeof(BITMAPINFOHEADER), 1, outptr);


    //for bi.Width ok!

            //write line in buffer ok!
            //skip padding ok!
            //for n times
                //for bi.width times ok!
                    //write pixel n times ok!
                //write new padding

    RGBTRIPLE buffer[bi.biWidth];

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        
        fread(&buffer, sizeof(RGBTRIPLE), bi.biWidth, inptr);
        fseek(inptr, padding, SEEK_CUR);
        for(int j = 0; j < n; j++)
        {
            for(int z = 0; z < bi.biWidth; z++)
            {
                for (int z2 = 0; z2 < n; z2++)
                    fwrite(&buffer[z], sizeof(RGBTRIPLE), 1, outptr);    
            }
            
         
            for (int k = 0; k < padding_output; k++)
                fputc(0x00, outptr);
        }

    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
