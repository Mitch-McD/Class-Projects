/*
 * Hands-on Project 9-1
 * Author: Mitchell McDaniel
 * Date:   4.4.2021
 * Filename: script.js
 */

function populateInfo() {
    if (location.search) {
        var greeting = location.search;
        greeting = greeting.replace("+", " ");
        greeting = greeting.substring(greeting.lastIndexOf("=") + 1);
        document.getElementById("greetingtext").innerHTML = decodeURIComponent(greeting);
    }
}

if (window.addEventListener) {
    window.addEventListener("load", populateInfo, false);
} else if (window.attachEvent) {
    window.attachEvent("onload", populateInfo);
}