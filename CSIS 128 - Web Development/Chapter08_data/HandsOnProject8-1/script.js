/*
    JavaScript 6th Edition
    Chapter 8
    Hands-on Project 8-1

    Author: Mitchell McDaniel
    Date:   3.27.2021

    Filename: script.js
*/
'use strict';
var newAccountArray = [];

function createID() {
    var fname = document.getElementById("fnameinput");
    var lname = document.getElementById("lnameinput");
    var zip = document.getElementById("zipinput");
    var account = document.getElementById("accountidbox");
    var fields = document.getElementsByTagName("input");
    var acctid, firstInit, lastInit;
    
    if(fname !== "" && lname !== "" && zip !== "") {
        firstInit = fname.value.charAt(0).toUpperCase();
        lastInit = lname.value.charAt(0).toUpperCase();
        acctid = firstInit + lastInit + zip.value;
        account.value = acctid;
        newAccountArray = [];
        window.alert(fields);
        for (var i = 0; i < fields.length - 1; i++) {
            newAccountArray.push(fields[i].value);
        }
        window.alert(newAccountArray);
    }
}

function createEventListeners() {
    var fname = document.getElementById("fnameinput");
    var lname = document.getElementById("lnameinput");
    var zip = document.getElementById("zipinput");
    
    if (fname.addEventListener) {
        fname.addEventListener("change", createID, false);
        lname.addEventListener("change", createID, false);
        zip.addEventListener("change", createID, false);
    } else if (fname.attachEvent) {
        fname.attachEvent("onchange", createID);
        lname.attachEvent("onchange", createID);
        zip.attachEvent("onchange", createID);
    }
}

if (window.addEventListener) {
    window.addEventListener("load", createEventListeners, false);
} else if (window.attachEvent) {
    window.attachEvent("onload", createEventListeners);
}