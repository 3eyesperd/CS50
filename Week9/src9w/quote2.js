$(document).ready(function() {

    // load data via ajax when form is submitted
    $('#form-quote input[name=symbol]').on('keyup', function() {

        // determine symbol
        var symbol = $('#form-quote input[name=symbol]').val();

        // send request to quote.php
        $.ajax({
            url: 'quote.php',
            type: 'POST',
            data: {
                symbol: symbol
            },
            success: function(response) {
                $('#price').text(response);
            }
        });
    });
});
