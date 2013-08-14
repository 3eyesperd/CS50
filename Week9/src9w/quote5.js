// object expected by yahoo finance autosuggest "api"
var YAHOO = {
    util: {
        ScriptNodeDataSource: {
            callbacks: function(data) {

                // create array of symbols
                var results = [];
                for (var i in data.ResultSet.Result)
                    results.push(data.ResultSet.Result[i].symbol);

                // display the array in the autocomplete
                window.callback(results);
            }
        }
    }
};

$(document).ready(function() {

    // create autocomplete
    $('#form-quote input[name=symbol]').typeahead({
        source: function(query, callback) {

            // remember how to display results in the autocomplete
            window.callback = callback;

            // send cross-domain request to yahoo finance
            $.ajax({
                url: 'http://d.yimg.com/aq/autoc',
                type: 'GET',
                dataType: 'jsonp',
                jsonpCallback: 'YAHOO.util.ScriptNodeDataSource.callbacks',
                data: {
                    query: query,
                    region: 'US',
                    lang: 'en-US',
                }
            });
        }
    });

    // load data via ajax when form is submitted
    $('#form-quote').on('submit', function() {

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

        // since we're overridding form submission, make sure it doesn't submit
        return false;
    });
});
