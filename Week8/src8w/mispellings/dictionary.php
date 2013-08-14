<?php

    /***********************************************************************
     * dictionary.php
     *
     * Computer Science 50
     * David J. Malan
     *
     * Implements a dictionary in a (non-object-oriented) way that
     * mimics Problem Set 5's implementation in C.  However, an 
     * object-oriented design would be better in PHP.
     **********************************************************************/

    // size of dictionary
    $size = 0;

    // hash table
    $table = array();

    /**
     * Returns true if word is in dictionary else false.
     */
    function check($word)
    {
        global $table;
        if (isset($table[strtolower($word)]))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    /**
     * Loads dict into memory.  Returns true if successful else false.
     */
    function load($dict)
    {
        global $table, $size;
        if (!file_exists($dict) && is_readable($dict))
        {
            return false;
        }
        foreach (file($dict) as $word)
        {
            $table[chop($word)] = true;
            $size++;
        }
        return true;
    }

    /**
     * Returns number of words in dictionary if loaded else 0 if not yet loaded.
     */
    function size()
    {
        global $size;
        return $size;
    }

    /**
     * Unloads dictionary from memory.  Returns true if successful else false.
     */
    function unload()
    {
        return true;
    }

?>
