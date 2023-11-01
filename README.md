# Search-Engine
Author - Sarthak Hans

## Description
This is a document search engine that locates relevant pages for a user's query with super-fast response time using map and set abstractions.

## Features
Clean Token: Extracts all punctuation from the beginning and end of a string and converts it to lowercase.
Gather Tokens: Extracts a set of unique tokens from the body text.
Build Index: Reads content from a database file and processes it into an inverted index.
Union Loop: Helper function to find URLs based on 'OR' condition.
Intersect Difference: Helper function to either intersect two sets or find the difference between two sets.
Find Query Matches: Finds URLs of single or compound terms searched from the loaded database.
Search Engine: Constructs inverted index, determines the number of webpages processed, and finally finds matching pages for a user-prompted search.
