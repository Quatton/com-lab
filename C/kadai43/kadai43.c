#include <stdio.h>

int main(int args, char *argv[]) {
  char *x[4] = {"enter", "new", "point", "first"};
  // an array of char pointers
  // here x[i] doesn't have to point to something next to each other in memory
  // but &x[i] (reference of itself) has to be next to each other in memory]
  // according to array definition

  char **xp[4];
  // an array of pointers to char pointers

  char ***xpp;
  // a pointer to a pointer to a pointer to a char

  int i;

  for (i = 0; i < 4; i++) xp[i] = x + (3 - i);
  // what this does is basically set xp[i] to x[3 - i]
  // in other words, reversed version of the array
  // xp[0] = x[3],
  // xp[1] = x[2],
  // xp[2] = x[1],
  // xp[3] = x[0]

  xpp = xp;
  // xpp points tothe first element of xp

  printf("%s", **++xpp);
  // this will print "point"
  // ++xpp means increment this first,
  // and substitute the incremented value here
  // so xpp now points to xp[1] which points to x[2]
  // **xpp = *x[2] = "point"

  printf("%s", *--*++xpp + 3);
  // this will print "er"
  // because of ++xpp from the previous call, xpp now points to xp[1]
  // ++: xpp now points to xp[2] which points to x[1]
  // *: deref it once, it will get xp[2]
  // --: xp[2] was pointing to x[1] decrementing it will make it point to x[0]
  // *: deref it again, it will get x[0]
  // +3: will jump to the 4th character of x[0] which is "e"
  // printing it will print until the end of the string
  // resulting in "er"

  printf("%s", *xpp[-2] + 3);
  // this will print "st"
  // xpp was pointing to xp[2] from the previous call
  // [-2]: accessing -2 will get xp[0] which points to x[3] ("first")
  // *: deref it once, it will get x[3] ("first")
  // +3: will jump to the 4th character of x[3] which is "s"
  // and yet again, printing it will print until the end of the string
  // resulting in "st"

  printf("%s\n", *--xpp[-1] + 1);
  // this will print "ew"
  // xpp was pointing to xp[2] from the previous call (didn't change)
  // [-1]: accessing -1 will give xp[1] which points to x[2] ("point")
  // --: decrementing it will make it point to x[1] ("new")
  // *: deref it once, it will get x[1]
  // +1: will jump to the 2nd character of x[1] which is "e"

  return 0;
}