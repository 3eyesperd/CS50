$(document).ready(function() {

    // key pressed in search field, so filter table
    $('#search').on('keyup', function() {

        // determine symbol we're searching for
        var query = $(this).val();

        // iterate over each row in the table
        $('#table-portfolio tbody tr').each(function(e) {

            // check if the symbol cell contains the query
            if (!query || $(this).children().first().text().toLowerCase().indexOf(query) > -1)
                $(this).show();

            // no match, so hide row
            else
                $(this).hide();
        });
    });

    // load table into ticker
    $('#table-portfolio tbody tr').each(function(e) {

        // get the cells in the row
        var children = $(this).children();

        // add all rows to ticker except the last, which is cash
        if (children.length > 2)
            $('#ticker').append('<span>' + children.eq(0).text() + ' ' + children.eq(3).text() + '</span> ');
    });

    // timer properties
    var speed = 30;
    var margin = 100;

    setInterval(function() {

        // move ticker towards the left
        margin--;

        // once ticker goes all the way left, reset to the right
        if (margin < -100)
            margin = 100;

        // set ticker position
        $('#ticker').css({ marginLeft: margin + '%' });
    }, speed);
});
