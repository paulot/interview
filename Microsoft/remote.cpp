// You are given a remote control with the letters of the alphabet like so:
// a b c d e f g
// h i j k l m n
// o p q r s t u
// v x w y z
// Write a program that prints the moves it takes to write a certain word 
// for example the word "dog" would be:
// rrr!ddlll!uurrrrrr!
// where ! means the button is clicked

#include <iostream>

char alphabet[23] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','x','w','y','z' }
int nCol = 7;

void getPos (
