/*  JavaScript 6th Edition
    Chapter 11
    Chapter HOP

    OMDB Search
    Author: Mitchell McDaniel
    Date:   4.18.21

    Filename: omdbscript.js
*/

"use strict";

// global variables
var httpRequest = false;
var titleSearchString = "";

function getRequestObject() {
	//attempt to create an AJAX request
	try {
		  httpRequest = new XMLHttpRequest();
	   }
	   catch (requestError) {
		  //display a warning that the browser doesn't support this type of web request
		  document.querySelector("section.movieresults table caption").innerHTML = "Your browser does not support this type of web request";
		  document.querySelector("section.movieresults table caption").style.display = "block";
		  return false;
	   }
	   return httpRequest;
}

function callOMDBSearchAPI(evt) {
   //stop processing the submit event so the script control the behavior
   if (evt.preventDefault) {
      evt.preventDefault();
   } else {
      evt.returnValue = false;
   }
   /************************Section 1*******************/
	//add code execute the web get request using the OMDB api
    titleSearchString = document.getElementsByTagName("input")[0].value;
    if (!httpRequest) {
        httpRequest = getRequestObject();
    }
    var apikey = "45a75a0c";
    var url = "http://www.omdbapi.com/?apikey=" + apikey + "&s=" + titleSearchString;
    
    httpRequest.abort();
    httpRequest.open("get", url, true);
    httpRequest.send();
    httpRequest.onreadystatechange = getMovieSearchResults;
    
   /****************************************************/
}

function getMovieSearchResults() {
	//make sure we have a valid response from the service before trying to process data
	if(httpRequest.readyState === 4 && httpRequest.status === 200) {
		var movieData = JSON.parse(httpRequest.responseText);
		console.log(movieData);

		//get the row elements from the document
		var rows = document.querySelectorAll("section.movieresults table tbody tr");
		
		/********************Section 3**********************/
		//add code to display data from movie search api results in the table
                document.querySelector("section.movieresults table caption").innerHTML = "Top 10 results for \"" + titleSearchString + "\"";
                document.querySelector("section.movieresults table thead").innerHTML = "Total found: " + movieData.totalResults;
                              
                for (var i = 0; i < rows.length && i < movieData.totalResults; i++) {
                    var title = rows[i].getElementsByTagName("td")[0];
                    var year = rows[i].getElementsByTagName("td")[1];
                    var type = rows[i].getElementsByTagName("td")[2];
                        title.innerHTML = movieData.Search[i].Title;
                        year.innerHTML = movieData.Search[i].Year;
                        type.innerHTML = movieData.Search[i].Type;
                }
		/****************************************************/
		
		//enable table and credit sections
		document.querySelector("section.movieresults table caption").style.display = "block";
		document.querySelector("section.movieresults table thead").style.display = "block";
		document.querySelector("section.movieresults table").style.display = "inline-block";
		document.querySelector("section.movieresults p.credit").style.display = "block";
	}
}

/*********************Section 2**********************/
//add event listener to call the function callOMDBSearchAPI

var form = document.getElementsByTagName("form")[0];
if (form.addEventListener) {
    form.addEventListener("submit", callOMDBSearchAPI, false);
} else if (form.attachEvent) {
    form.attachEvent("onsubmit", callOMDBSearchAPI);
}

/****************************************************/