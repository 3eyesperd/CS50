/****************************************************************************
 * resize.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Resizes a BMP
 ***************************************************************************/
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: resize n infile outfile\n");
        return 1;
    }

    int n = atoi(argv[1]);

    // remember filenames
    char* infile = argv[2];
    char* outfile = argv[3];

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

    // format BITMAPINFOHEADER
    BITMAPINFOHEADER bi_output = bi;
    bi_output.biWidth = bi.biWidth*n;
    bi_output.biHeight = bi.biHeight*n;
    int output_padding =  (4 - (bi_output.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    bi_output.biSizeImage = sizeof(RGBTRIPLE)*(bi_output.biHeight)*(bi_output.biWidth +output_padding);
    



    // format BITMAPFILEHEADER
    BITMAPFILEHEADER bf_output = bf;
    bf_output.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + bi_output.biSizeImage;


    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // write outfile's BITMAPFILEHEADER
    
    fwrite(&bf_output, sizeof(BITMAPFILEHEADER), 1, outptr);




    // write outfile's BITMAPINFOHEADER
    fwrite(&bi_output, sizeof(BITMAPINFOHEADER), 1, outptr);

    // determine padding for scanlines
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        RGBTRIPLE line[bi_output.biWidth + output_padding];
        for (int j = 0; j < bi.biWidth; j++)
        {
            // temporary storage
            RGBTRIPLE triple;
            
            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            
            for (int k = 0; k < n; k++)
            {
                line[n*j +k] = triple;
            }
            
        }

        // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);

        //write the line n times

        for (int k = 0; k < n; k++)
        {
            for( int z = 0; z < bi_output.biWidth; z++)
            {

                fwrite(&line + z, sizeof(RGBTRIPLE), 1, outptr);    
            }
            
        }

        // then add it back (to demonstrate how)
        for (int k = 0; k < output_padding; k++)
            fputc(0x00, outptr);
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
