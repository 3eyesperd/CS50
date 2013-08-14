/****************************************************************************
 * puff.c
 *
 * Computer Science 50
 * Problem Set 6
 *
 * Decompress contents of a huff-compressed file in the original file.
 ***************************************************************************/



#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "forest.h"
#include "huffile.h"
#include "tree.h"

// first and last symbols to dump
#define FIRST '!'
#define LAST '~'

// number of columns to use
#define COLS 8


Forest* combine(Forest*);

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 3)
    {
        printf("Usage: %s input output\n", argv[0]);
        return 1;
    }

    // open input
    Huffile* input = hfopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open %s for reading.\n", argv[1]);
        return 1;
    }

    // read in header
    Huffeader header;
    if (hread(&header, input) == false)
    {
        hfclose(input);
        printf("Could not read header.\n");
        return 1;
    }

    // check for magic number
    if (header.magic != MAGIC)
    {
        hfclose(input);
        printf("File was not huffed.\n");
        return 1;
    }

    // check checksum
    int checksum = header.checksum;
    for (int i = 0; i < SYMBOLS; i++)
    {
        checksum -= header.frequencies[i];
    }
    if (checksum != 0)
    {
        hfclose(input);
        printf("File was not huffed.\n");
        return 1;
    }

    FILE* output = fopen(argv[2], "w");
    

    // Creates forest
    Forest* forest = mkforest();
    Tree* tempTree = NULL;

    // create trees of non-0 frequencies
    for (int i = 0; i < SYMBOLS; i++)
    {
        if (header.frequencies[i] > 0)
        {
            tempTree = mktree();
            tempTree->frequency = header.frequencies[i];
            tempTree->symbol = i;
            tempTree->left = NULL;
            tempTree->right = NULL;
            plant(forest, tempTree);
        }
    }

    forest = combine(forest);
    Tree* Huffman = pick(forest);


    Tree* treewalker = Huffman;

    for (int bit = bread(input); bit != EOF; bit = bread(input))
    {
        if (bit == 0)
            treewalker = treewalker->left;
        
        if (bit == 1)
            treewalker = treewalker->right;

        if ((treewalker->left == NULL) && (treewalker->right == NULL))
        {
            fprintf(output, "%c", treewalker->symbol);
            treewalker = Huffman;
        }
    }

    // that's all folks!
    return 0;
}


Forest* combine(Forest* forest)
{
    Tree* tree1 = pick(forest);
    Tree* tree2 = pick(forest);

    if (tree2 == NULL)
    {
        plant(forest, tree1);
        return forest;
    }

    else
    {
        Tree* combined = mktree();
        combined->frequency = (tree1->frequency + tree2->frequency);
        combined->left = tree1;
        combined->right = tree2;
        plant(forest, combined);
        return combine(forest);

    }
}

