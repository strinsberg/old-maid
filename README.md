# 3720 Card Game

[![build status](http://gitlab.cs.uleth.ca/deus3720/OldMaid/badges/master/build.svg)](http://gitlab.cs.uleth.ca/deus3720/OldMaid/commits/master)

A command line Old maid card game utilizing MVC architecture.

# Organization
* Documentation can be generated with ```$ make docs``` and will be stored in ```docs/code/html```
* Some system and class diagrams can be found in ```docs/design```
* All header files for non-mock classes are in ```include```
* All src files are in ```src```
* The program main.cpp is in ```src/game```
* All test suites and mock headers are in ```test```

# Notes
* Most classes should be open to extension.
* Some design decisions were made to attempt to make it possible to reuse components with new games, however, it is debateable how easy it will actually be.
* The player controller class was specifically created to allow polymorphic AI, unfortunatley this never made it into the game. However, this controller object also makes the game logic for rounds and player turns a bit simpler by splitting them up. It also makes it easier to test and mock them.
