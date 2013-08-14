<?php

    /****************************************************************************
     * beer1.php
     *
     * David J. Malan
     * malan@harvard.edu
     *
     * Sings "99 Bottles of Beer on the Wall."
     *
     * Demonstrates a for loop.
     ***************************************************************************/

    // ask user for number
    $n = readline("How many bottles will there be? ");

    // exit upon invalid input
    if ($n < 1)
    {
        printf("Sorry, that makes no sense.\n");
        exit(1);
    }

    // sing the annoying song
    printf("\n");
    for ($i = $n; $i > 0; $i--)
    {
        printf("%d bottle(s) of beer on the wall,\n", $i);
        printf("%d bottle(s) of beer,\n", $i);
        printf("Take one down, pass it around,\n");
        printf("%d bottle(s) of beer on the wall.\n\n", $i - 1);
    }

    // exit when song is over
    printf("Wow, that's annoying.\n");
    exit(0);

?>
