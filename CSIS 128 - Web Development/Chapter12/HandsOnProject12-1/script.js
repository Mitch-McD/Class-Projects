/*
   JavaScript 6th Edition
   Chapter 12
   Hands-on Project 12-1

   Author: Mitchell McDaniel
   Date:   4/25/2021

   Filename: index.htm
*/

function display(event) {
    $(event.currentTarget).next().fadeIn("slow");
}

var h3 = document.getElementsByTag("h3");
for (var i = 0; i < h3.length; i++) {
    h3[i].addEventListener("click", display, false);
}



