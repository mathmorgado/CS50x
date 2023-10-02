document.addEventListener("DOMContentLoaded", function() {

    if (document.querySelector('#know-more'))
    {
        let buttom = document.querySelector('#know-more');
        buttom.addEventListener('click', function() {
            alert("This are the best moments I have with them")
        });
    }
    else
    {
        let me = document.getElementById('me');
        me.addEventListener('mouseover', function() {
            alert("I have difficulty with the front-end, but I kind of like it");
        });
    }
});