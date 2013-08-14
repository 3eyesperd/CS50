<?php

    // configuration
    require("../includes/config.php"); 

    // if form was submitted
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // validate submission
        if (empty($_POST["symbol"]))
        {
            exit;
        }

        // look up quote
        $stock = lookup($_POST["symbol"]);
        if ($stock === false)
        {
            exit;
        }

        $price = number_format($stock['price'], 2);
        echo "A share of {$stock['name']} costs $price.";
    }
    else
    {
        // else render form
        render("quote_form.php", ["title" => "Get Quote"]);
    }

?>
